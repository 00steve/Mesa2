#include "../include/node.h"

//static class variable initialization
std::list<Node*> Node::garbage = std::list<Node*>();
unsigned long Node::nodeIdIterator = 1;

bool Node::AddChild(Node* newChild){
    if(!AddChildThis(newChild)) return false;
    newChild->Parent(this);
    children.push_back(newChild);
    AddDependency(newChild);
    return true;
}

bool Node::AddChildThis(Node* newChildNode){
    return true;
}


void Node::AddDependency(Node* newDependency){
    if(!newDependency) return;
    //std::cout << "add dependency : " << Name() << " depends on " << newDependency->Name() << std::endl;
    dependencies.push_back(newDependency);
}

std::list<Node*> Node::Children(){
    return children;
}

std::string Node::CustomProperty(const int propertyCode){
    return "";
}


void Node::UpdateThis(){
}

int Node::ChildDepth(){
    return childDepth;
}

int Node::ChildDepth(unsigned int newChildDepth){
    if(parent) return childDepth;
    return childDepth = newChildDepth;
}

unsigned long Node::DependencyCount(){
    return dependencies.size();
}

void Node::DepthPrint(std::string text){
    std::string indent = "";
    int i = ChildDepth();
    while(i --> 0){
        indent += '\t';
    }
    std::cout << indent << text << std::endl;
}

void Node::EmptyGarbage(){
    Node* c = NULL;
    for(std::list<Node*>::iterator it = garbage.begin(); it != garbage.end(); ++it){
        auto chit = *it;
        it = garbage.erase(it);
        //delete chit;
    }
}

unsigned long Node::Id(){
    return nodeId;
}

bool Node::IsGarbage(){
    return isGarbage;
}

std::string Node::Name(){
    return name;
}

std::string Node::Name(std::string newName){
    return this->name = newName;
}

Node::Node() : 
        isGarbage(false),
        nodeId(Node::nodeIdIterator++) {
    name = "Node " + std::to_string(nodeId);
}

Node::~Node(){
    std::cout << "delete node : " << name << "\n";
    RemoveAllDependencies();
    for(std::list<Node*>::iterator oc = children.begin(); oc != children.end(); ){
        delete *oc;
        children.erase(oc);
    }
}

Node* Node::Parent(){
    return parent;
}

void Node::Parent(Node* newParent){
    childDepth = newParent ? newParent->ChildDepth()+1 : Node_DEFAULT_CHILD_DEPTH;
    parent = newParent;
    if(newParent){
        AddDependency(newParent);
    }
}

void Node::Print(){
    DepthPrint(std::to_string(nodeId));
    for(std::list<Node*>::iterator child = children.begin(); child != children.end(); ){
        (*child)->PrintChildHeirarchy();
        ++child;
    }
}

void Node::Print(const std::function<std::string(Node*)>& fn){
    DepthPrint(fn(this));
    for(std::list<Node*>::iterator child = children.begin(); child != children.end(); ){
        (*child)->Print(fn);
        ++child;
    }
}

void Node::PrintChildHeirarchy(){
    DepthPrint(name);
    for(std::list<Node*>::iterator child = children.begin(); child != children.end(); ){
        (*child)->PrintChildHeirarchy();
        ++child;
    }
}

std::string Node::Property(const int propertyCode){
    std::string prop = CustomProperty(propertyCode);
    //return property values that cannot be overridden by
    //inheriting classes
    switch(propertyCode){
    case NodeProperty::ID:
        return std::to_string(nodeId);
    }
    //let the inheriting class override stuff and return
    //its own values and other junk
    if(prop != "") return prop;
    //default return values for if there is nothing being
    //overridden by the inheritting class
    switch(propertyCode){
    case NodeProperty::NAME:
        return name;
    case NodeProperty::TYPE:
        return "NODE";
    default:
        return "";
    }
}

void Node::RemoveAllDependencies(){
    std::cout << "- remove all dependencies from " << Name() << " : " << DependencyCount() << " dependencies\n";
    for(std::list<Node*>::iterator oc = dependencies.begin(); oc != dependencies.end(); ){
        std:: cout << "     - dependency to [" << (*oc)->Name() << "]\n";
        ++oc;
    }
    for(std::list<Node*>::iterator oc = dependencies.begin(); oc != dependencies.end(); ){
        (*oc)->RemoveDependency(this);
        RemoveDependency(*oc);
        oc = dependencies.erase(oc);
    }
}

void Node::RemoveAllReferencesToNode(Node* oldNode){
    for(std::list<Node*>::iterator oc = children.begin(); oc != children.end(); ){
        if(*oc != oldNode) {
            ++oc;
            continue;
        }
        if(oldNode->Parent() == this){
            std::cout << "      - set parent : of " << oldNode->Name() << " as null\n";
            oldNode->Parent(NULL);
        }
        std::cout << "      - remove child : " << oldNode->Name() << " from " << this->Name() << std::endl;
        children.erase(oc);
        break;
    }
    for(std::list<Node*>::iterator oc = dependencies.begin(); oc != dependencies.end(); ){
        if(*oc != oldNode) {
            ++oc;
            continue;
        }
        //std::cout << " - remove dependency : " << (*oc)->Name() << std::endl;
        //dependencies.erase(oc);
        RemoveThisDependency(oldNode);
        break;
    }
}

Node* Node::RemoveChild(Node* oldChild){
    RemoveAllReferencesToNode(oldChild);
    return NULL; 
}

Node* Node::RemoveDependency(Node* oldDependency){
    std::cout << "  - remove dependency from " << Name() << " :" << std::endl;
    RemoveAllReferencesToNode(oldDependency);
    return oldDependency;
}

void Node::RemoveThisDependency(Node* oldDependency){
}


bool Node::ThrowAway(){
    if(isGarbage) return false;
    garbage.push_back(this);
    return isGarbage = true;
}

void Node::Update(){
    UpdateThis();
    UpdateChildren();
}

void Node::UpdateTick(){

}

void Node::UpdateChildren(){
    for(std::list<Node*>::iterator child = children.begin(); child != children.end(); ){
        (*child)->Update();
        ++child;
    }
}
