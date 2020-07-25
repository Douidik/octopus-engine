#ifndef OCTOPUS_NONCOPYABLE_H
#define OCTOPUS_NONCOPYABLE_H

class INonCopyable {
public:
    INonCopyable() = default;
    INonCopyable(const INonCopyable&) = delete;
    INonCopyable &operator=(const INonCopyable&) = delete;
};

#endif //OCTOPUS_NONCOPYABLE_H
