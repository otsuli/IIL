#pragma once
#include <cstddef>
#include <memory>
#include <new>

struct ArenaChunk {
    // pointer to start of raw memory:
    char *buffer;
    std::size_t capacity;
    // how much is used:
    std::size_t offset;
    ArenaChunk *nextChunk;
};

class Arena {
    // First chunk:
    ArenaChunk *head_;
    ArenaChunk *current_Chunk_;
    // Start of memory block
    char *buffer_;
    size_t capacity_;
    // Amount of memory already used mapping to the current position in the arena.
    size_t offset_;

  public:
    ArenaChunk *create_chunk(size_t size) {
        ArenaChunk *chunk = new ArenaChunk;

        chunk->buffer = static_cast<char *>(::operator new(size));
        chunk->capacity = size;
        chunk->offset = 0;
        chunk->nextChunk = nullptr;

        return chunk;
    }
    Arena::Arena() {
        head_ = create_chunk(256 * 1024); // 1KB
        current_Chunk_ = head_;
    }

    ~Arena() { ::operator delete(buffer_); }

    void *allocate(std::size_t size, std::size_t alignment);

    void reset();
    // Delete the the copy and move constructors:
    Arena(const Arena &) = delete;
    Arena(Arena &&) = delete;
};
