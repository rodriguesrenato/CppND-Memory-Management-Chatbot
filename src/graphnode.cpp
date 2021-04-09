#include "graphnode.h"

#include "graphedge.h"

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode() {}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
    _parentEdges.push_back(edge);
}

// receive a unique pointer GraphEdge reference and push it back to _childEdges
// transfering it's ownership
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> &edge) {
    _childEdges.push_back(std::move(edge));
}

// receive a ChatBot reference and transfer its ownership to _chatBot attribute
void GraphNode::MoveChatbotHere(ChatBot &chatbot) {
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

// move _chatBot reference to newNode
void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
    newNode->MoveChatbotHere(_chatBot);
}

// return a child GraphEdge pointer reference at the specific index of
// _childEdges vector
GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
    return _childEdges[index].get();
}