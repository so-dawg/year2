#include <iostream>
#include <chrono>

struct SLLNode {
    int data;
    SLLNode* next;
};

struct CSLLNode {
    int data;
    CSLLNode* next;
};

struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
};

template<typename NodeType>
void allocateNodes(size_t n, const std::string& label) {
    auto start = std::chrono::high_resolution_clock::now();

    NodeType* nodes = new NodeType[n];
    for (size_t i = 0; i < n; ++i) {
        nodes[i].data = i;
        nodes[i].next = (i < n - 1) ? &nodes[i + 1] : nullptr;
        if constexpr (std::is_same<NodeType, DLLNode>::value) {
            nodes[i].prev = (i > 0) ? &nodes[i - 1] : nullptr;
        }
        if constexpr (std::is_same<NodeType, CSLLNode>::value && i == n - 1) {
            nodes[i].next = &nodes[0]; // circular link
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    size_t nodeSize = sizeof(NodeType);
    size_t totalSize = nodeSize * n;

    std::cout << label << ":\n";
    std::cout << "  Node size: " << nodeSize << " bytes\n";
    std::cout << "  Total size: " << totalSize / (1024.0 * 1024.0) << " MB\n";
    std::cout << "  Allocation time: " << duration.count() << " seconds\n\n";

    delete[] nodes;
}

int main() {
    size_t n = 1000000;

    allocateNodes<SLLNode>(n, "SLL");
    allocateNodes<CSLLNode>(n, "CSLL");
    allocateNodes<DLLNode>(n, "DLL");

    return 0;
}

