//
// Created by raulm on 3/23/2024.
//

#ifndef LAB3_DSM_H
#define LAB3_DSM_H
#include <string>
#include "Vector.cpp"

class DSM {
private:
    int _elementCount;
    int** _matrix;
//    std::string* _elementNames[];
    Vector<std::string >*_elementNames;
public:
    DSM(int elementCount);

    DSM(std::string elementNames[],int elementCount);

    DSM(const DSM& other);

    int size() const;

    std::string getName(int index){return (this->_elementNames)->getElem(index);}

    void setElementName(int index, std::string elementName){return (this->_elementNames)->modifyElem(index,elementName);}

    void addLink(std::string fromElement, std::string toElement,int weight);

    void deleteLink(std::string fromElement,std::string toElement);

    bool hasLink(std::string fromElement, std::string toElement);

    int linkWeight(std::string fromElement, std::string toElement);

    int countToLinks(std::string elementName);

    int countFromLinks(std::string elementName);

    int countAllLinks();

    void printMatrix();

    void resizeMatrix(int n);

    ~DSM();
};


#endif //LAB3_DSM_H
