#ifndef UTIL_Node
#define UTIL_Node

#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <iostream>
#include <functional>

#define Node_DEFAULT_CHILD_DEPTH 0;

enum NodeProperty {CHILDCOUNT,TYPE,ID,NAME,INNERTEXT};

class Node{
private:
    /*If the node has no parent, the childDepth value will be 0. If it has a
    parent set, it will have a child depth of whatever the parent has + 1.*/
    int childDepth = Node_DEFAULT_CHILD_DEPTH;
    /*an array of child nodes that this node contains*/
    std::list<Node*> children;
    /*or maybe there should be an array of referencing nodes? Not quite sure
    how I want to deal with this yet.*/
    std::list<Node*> dependencies;
    /*store a list of nodes to be deleted*/
    static std::list<Node*> garbage;
    /*store a flag that says if a node should be garbage collected or not*/
    bool isGarbage;
    /*The unique name of each node (at least it should be unique)*/
    std::string name;
    unsigned long nodeId;
    /*used to iterate across all node class objects to set the next id that 
    should be unique for each node object. It's set to unsigned long so you
    won't run out of new ids unless you're a crazy person.*/
    static unsigned long nodeIdIterator;
    /*by default, a node doesn't have a parent. It is just an aimless stray
    trying to make it out there in the harsh world.*/
    Node* parent = NULL;

    void Parent(Node* newParent);
    void RemoveAllDependencies();
    void RemoveAllReferencesToNode(Node* oldNode);
    void UpdateChildren();

protected:
    virtual bool CustomAddChild(Node* newChild);
    virtual std::string CustomProperty(const int propertyCode);
    /*This should be implemented by any inheriting class that stores pointers 
    to any other nodes.*/
    virtual void RemoveThisDependency(Node* oldDependency);
    void DepthPrint(std::string text);
    virtual void UpdateThis();

public:
    /*will add a node to the children array. If the CustomAddChild() virtual
    function is implemented by an inheriting class, it will attempt to call 
    that function first. If it fails to add it (returns false) it will abort 
    trying to add the child to the children array as well.*/
    bool AddChild(Node* newChild);
    /*add a new node to the list of nodes that this node depends on.*/
    void AddDependency(Node* newDependency);

    int ChildDepth();
    /*Manually set the child depth of a node. This only works if it currently
    doesn't have a parent node. If it has a parent, the value is not updated 
    and the depth of the node under the current parent is returned.*/
    int ChildDepth(unsigned int newChildDepth);
    std::list<Node*> Children();
    static void EmptyGarbage();
    unsigned long DependencyCount();
    unsigned long Id();
    bool IsGarbage();
    /*Return the name of the node. The default name will be "NODE " + the node's
    ID. This can be overridden to give a more specific or meaningful name."*/
    virtual std::string Name();
    std::string Name(std::string newName);
    Node();
    ~Node();
    Node* Parent();
    void Print();
    void Print(const std::function<std::string(Node*)>& fn);
    void PrintChildHeirarchy();
    std::string Property(const int propertyCode);
    Node* RemoveChild(Node* oldChild);
    /*remove an object from the list that this node no longer depends on*/
    Node* RemoveDependency(Node* oldDependency);
    /*Will set the isGarbage flag so the node is deleted whenever the 
    garbage collection runs*/
    bool ThrowAway();
    void Update();
    void UpdateTick();

};


#endif