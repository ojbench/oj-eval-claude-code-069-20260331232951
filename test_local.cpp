#include <iostream>
#include "template.h"

using namespace sjtu;

int main() {
    // Test 1: Simple allocation
    resetMemory();
    std::cout << "Test 1: Simple allocation\n";
    MemoryBlock* block1 = allocate(100);
    if (block1) {
        std::cout << "Allocated block at address " << block1->address
                  << " with size " << block1->size << std::endl;
    } else {
        std::cout << "Allocation failed\n";
    }

    // Test 2: Multiple allocations
    std::cout << "\nTest 2: Multiple allocations\n";
    MemoryBlock* block2 = allocate(200);
    MemoryBlock* block3 = allocate(300);
    if (block2 && block3) {
        std::cout << "Allocated block2 at address " << block2->address
                  << " with size " << block2->size << std::endl;
        std::cout << "Allocated block3 at address " << block3->address
                  << " with size " << block3->size << std::endl;
    }

    // Test 3: Deallocation
    std::cout << "\nTest 3: Deallocation\n";
    deallocate(block2);
    std::cout << "Deallocated block2, is_free: " << block2->is_free << std::endl;

    // Test 4: Reuse freed block
    std::cout << "\nTest 4: Reuse freed block\n";
    MemoryBlock* block4 = allocate(150);
    if (block4) {
        std::cout << "Allocated block4 at address " << block4->address
                  << " with size " << block4->size << std::endl;
    }

    // Test 5: Coalescing
    std::cout << "\nTest 5: Coalescing\n";
    deallocate(block1);
    std::cout << "Deallocated block1\n";
    std::cout << "Head is_free: " << head->is_free << ", size: " << head->size << std::endl;

    return 0;
}
