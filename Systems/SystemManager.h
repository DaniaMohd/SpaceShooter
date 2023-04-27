#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

class System{
    virtual void Init(std::shared_ptr<GameObject> gObj){}
    virtual void Update(std::shared_ptr<GameObject> gObj, float dt)
}

class SystemManager{
    std::vector<
}

#endif /* SYSTEMMANAGER_H */
