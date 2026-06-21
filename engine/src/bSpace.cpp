#include "../include/bSpace.h"


BSpace::BSpace(AABB bounds) : 
    bounds(bounds)
        {
    Init();
}

void BSpace::CustomDraw(){
    //float t = (float)glfwGetTime();
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 0.0f));
    transformationMatrix = GetCurrentProjectionMatrix() * GetCurrentViewMatrix() * trans;
    glUseProgram(shaderMap->shaderProgramId);
    glUniformMatrix4fv(glGetUniformLocation(shaderMap->shaderProgramId, "MVP"), 1, GL_FALSE, &transformationMatrix[0][0]);
    glUniform3fv(glGetUniformLocation(shaderMap->shaderProgramId, "color"), 1, &lineColor[0]);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, 16);
}

void BSpace::Init(){
    shaderMap = FindShaderMap("line");

    lineColor = glm::vec3(.3,.4,.3);
    transformationMatrix = glm::mat4(1.0f);
    vertexL = {
        (float)bounds.LowerBounds().x, (float)bounds.LowerBounds().y, (float)bounds.LowerBounds().z,
        (float)bounds.UpperBounds().x, (float)bounds.UpperBounds().y, (float)bounds.UpperBounds().z
    };
    std::vector<uint> vertexIs = {
        3,4,5, 3,4,2, 0,4,2, 0,4,5, 
        3,1,5, 3,1,2, 0,1,2, 0,1,5
    };
    std::vector<float3> vectors = ConvertNumbersToVectors(vertexL,vertexIs);
    /*
    for(auto i: vectors)
        std::cout << i.x << "," << i.y << "," << i.z << "\n";
    std::cout << " size of vector : " << sizeof(vectors[0]) << '\n';
    */
    std::vector<uint> stripIs = {
        0,1,2,3,0,4,5,6,7,4,7,3,2,6,5,1
    };
    std::vector<float> lbuff = ConvertVectorsToLineStrip(vectors,stripIs);
    
    //for(auto i: lbuff)
        //std::cout << i << "\n";
    
   /*alternate, probably better way to directly create a list of floats to send to
   a VBO, but it's being commented out for now, because the two step process gives 
   me the flexibility to mess around with the strip order more easily.
    std::vector<uint> lnstBuffIs = {
        3,4,2, 0,4,2, 0,4,5,
        3,4,5, 3,4,2, 3,1,2,
        0,1,2, 0,1,5, 3,1,5,
        3,1,2, 3,4,5, 3,1,5,
        0,4,5, 0,1,5, 0,4,2,
        0,1,2, 3,4,2
    };
    std::vector<float> lnstBuff = ConvertNumbersToLineStrip(vertexL,lnstBuffIs);
    
    for(auto i: lnstBuff)
        std::cout << i << "\n";
        */

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, lbuff.size()*sizeof(float), lbuff.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    //unbind everything?
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 
}