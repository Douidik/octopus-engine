#ifndef APPLICATION_ICOUNTED_H
#define APPLICATION_ICOUNTED_H

/* This class count how many instance lives */
class ICounted {
public:
    ICounted() {
        s_uInstanceCount++;
    }

    ~ICounted() {
        s_uInstanceCount--;
    }

    // Returns how many instance of the class are instancied
    inline static unsigned int InstanceCount() {
        return s_uInstanceCount;
    }

    // Returns whether or not an instance of the class is instancied
    inline static bool IsInstancied() {
        return s_uInstanceCount >= 0;
    }

private:
    static unsigned int s_uInstanceCount;
};

#endif //APPLICATION_ICOUNTED_H
