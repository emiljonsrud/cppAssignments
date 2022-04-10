#include "LinkedList.h"

std::ostream& LinkedList::operator<<(std::ostream& os, const Node& node) {
    os << node.getValue();
    return os;
}

LinkedList::Node* LinkedList::LinkedList::insert(Node* pos, const std::string& value) {
    // Node* newNode = new Node{value, std::move(prevNode->next), pos->prev};

    // Create new node pointing forwards and backwards
    Node* newNode = new Node{
        value,
        std::unique_ptr<Node>(pos),
        pos->prev
    };
    
    if(pos->prev == nullptr) {
        // If the prev pointer is null, then this is the first node
        head = std::unique_ptr<Node>(newNode);
    } else {
        // Define a pointer to the previous node
        Node* prevNode = pos->prev;
        std::cout << prevNode->getValue() << std::endl;
        prevNode->next = std::unique_ptr<Node>(newNode);
        
        // (newNode->getPrev())->next = std::unique_ptr<Node>(newNode);
        // ^^^^^Denne syntaksen er veldig rar, finnes det en
        //      bedre måte?
    }
    
    pos->prev = newNode;

    // // Find the previous node, and move ownership of its next pointer to a new node
    // Node* prevNode = pos->getPrev();
    // Node* newNode = new Node{value, std::move(prevNode->next), pos->prev};
    
    // pos->prev = newNode;

    // // Move ownership of this new node to the previous node
    // prevNode->next = std::unique_ptr<Node>(newNode);

    
    return newNode;
}

LinkedList::Node* LinkedList::LinkedList::remove(Node* pos) {
    // Update the next nodes prev to point at the prev node
    (pos->getNext())->prev = pos->getPrev();
    
    // Update the prevous' next pointer to point at the next ponter
    (pos->getPrev())->next = std::move(pos->next);

    return pos->getNext();
}

LinkedList::Node* LinkedList::LinkedList::find(const std::string& value) {
    // Start by pointing at the head
    Node* itNode = head.get();
    
    // Traverse the link as long as we havent reached the tail
    while(itNode != tail) {

        // Check if the current nodes value is l
        std::string itStr = itNode->getValue();
        if (itStr == value) {
            return itNode;
        }
    }
    return itNode;
}

void LinkedList::LinkedList::remove(const std::string& value) {
    Node* rmNode = find(value);
    remove(rmNode);
}

std::ostream& LinkedList::operator<<(std::ostream &os, const LinkedList& list) {
    // Keep rack of the index position
    int i {0};

    // Iterate the nodes from the head
    Node* itNode = list.begin();
    while(itNode != list.end()) {
        os << std::setw(3) << std::right << std::to_string(i) << ": ";
        os << std::setw(20) << std::right << itNode->getValue() << std::endl;
        itNode = itNode->getNext();
        i++;
    }    
    return os;
}