#include "../../include/displayable/line.h"

void line::AssignColors(double3* c0, double3* c1){
    if(!colors){
        colors = new double3*[2];
    }
    colors[0] = c0;
    colors[1] = c1;
}

void line::AssignVertices(double3* v0, double3* v1){
    if(!vertices){
        vertices = new double3*[2];
    }
    vertices[0] = v0;
    vertices[1] = v1;
}

void line::DrawThis(){
    //glm::mat4 trans = glm::mat4(1.0f);
    //trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 0.0f));
    transformationMatrix = GetCurrentProjectionMatrix() * GetCurrentViewMatrix();// * trans;
    
    vertexL[0] = (float)vertices[0]->x;
    vertexL[1] = (float)vertices[0]->y;
    vertexL[2] = (float)vertices[0]->z;
    vertexL[3] = (float)vertices[1]->x;
    vertexL[4] = (float)vertices[1]->y;
    vertexL[5] = (float)vertices[1]->z;

    //std::cout << "vert[0] = " << vertices[0] << "\n";

    glNamedBufferSubData(VBO,0,sizeof(vertexL), vertexL.data());

    glUseProgram(shaderMap->shaderProgramId);
    glUniformMatrix4fv(glGetUniformLocation(shaderMap->shaderProgramId, "MVP"), 1, GL_FALSE, &transformationMatrix[0][0]);
    glUniform3fv(glGetUniformLocation(shaderMap->shaderProgramId, "color"), 1, &lineColor[0]);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 2);

}

void line::Init(double3* v0, double3* v1, double3* c0, double3* c1){
    AssignVertices(v0,v1);
    AssignColors(c0,c1);
    //std::cout << "gl version: " << glGetString(GL_VERSION) << std::endl;
    shaderMap = FindShaderMap("line");
    if(shaderMap){
        //std::cout << "fragment shader id : " << shaderMap->fragmentShaderId << " vertex shader id : " << shaderMap->vertexShaderId << std::endl;
    }

    //openGL shit
    lineColor = glm::vec3(1,0,0);
    transformationMatrix = glm::mat4(1.0f);
    vertexL = {
        (float)vertices[0]->x, (float)vertices[0]->y, (float)vertices[0]->z,
        (float)vertices[1]->x, (float)vertices[1]->y, (float)vertices[1]->z
    };
    /*std::cout << "setup line VBO : (" << vertexL[0] << "," << vertexL[1] << "," << vertexL[2] << ")," 
        << "(" << vertexL[3] << "," << vertexL[4] << "," << vertexL[5] << ")\n";*/

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexL), vertexL.data(), GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    //unbind everything?
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 


}

line::line(){
    internalVertices = new double3[4];
    internalVertices[0] = double3(1,0,0);
    internalVertices[1] = double3(0,1,0);
    internalVertices[2] = double3(1,1,0);
    internalVertices[3] = double3(0,1,1);
    Init(&internalVertices[0], &internalVertices[1], &internalVertices[2], &internalVertices[3]);
}

line::line(double3 v0, double3 v1){
    internalVertices = new double3[4];
    internalVertices[0] = double3(v0.x,v0.y,v0.z);
    internalVertices[1] = double3(v1.x,v1.y,v1.z);
    internalVertices[2] = double3(1,1,0);
    internalVertices[3] = double3(0,1,1);
    Init(&internalVertices[0], &internalVertices[1], &internalVertices[2], &internalVertices[3]);
}

line::line(double3* v0, double3* v1){
    Init(v0, v1, new double3(), new double3());
}

line::~line(){
}

bool line::SetShader(std::string shader){
    shaderMap = FindShaderMap("line");
    return shaderMap != 0;
}

bool line::UpdateVertices(double3 v0, double3 v1){
    if(!internalVertices){
        std::cout << "This line uses pointers to vertices stored somewhere else. Update them.\n";
        return 0;
    }
    internalVertices[0] = v0;
    internalVertices[1] = v1;
    return 1;
}