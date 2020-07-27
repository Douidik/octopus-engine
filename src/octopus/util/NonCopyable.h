#ifndef OCTOPUS_NONCOPYABLE_H
#define OCTOPUS_NONCOPYABLE_H

class NonCopyable {
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable &operator=(const NonCopyable&) = delete;
};

#endif //OCTOPUS_NONCOPYABLE_H
