#include "LinkedList.h"

std::ostream& operator<<(std::ostream& os, const LinkedList::Node& node) {
    os << node.getValue();
    return os;
}

LinkedList::Node* LinkedList::LinkedList::insert(Node* pos, const std::string& value) {
    // Find the previous node, and move ownership of its next pointer to a new node
    Node* prevNode = pos->getPrev();
    Node* newNode = new Node{value, std::move(prevNode->next), pos->prev};
    
    pos->prev = newNode;

    // Move ownership of this new node to the previous node
    prevNode->next = std::unique_ptr<Node>(newNode);
    
    return newNode;
}

LinkedList::Node* LinkedList::LinkedList::remove(Node* pos) {
    // Update the next nodes prev to point at the prev node
    (pos->getNext())->prev = pos->getPrev();
    
    // Update the prevous' next pointer to point at the next ponter
    (pos->getPrev())->next = std::move(pos->next);

    return pos->getNext();
}