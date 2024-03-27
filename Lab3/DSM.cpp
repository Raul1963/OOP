//
// Created by raulm on 3/23/2024.
//

#include "DSM.h"
using namespace std;
DSM::DSM(int elementCount) {
    this->_elementCount=elementCount;
    this->_elementNames=new Vector<string>(this->_elementCount);
    this->_matrix = new int*[elementCount];
    for (int i = 0; i < elementCount; i++)
    {
        this->_matrix[i] = new int[elementCount];
    }
    for (int i = 0; i < elementCount; i++)
        for (int j = 0; j < elementCount; j++)
            this->_matrix[i][j] = 0;

    for (int i=0;i<this->_elementCount;i++){
        (this->_elementNames)->add("");
    }

//    int matrix[elementCount][elementCount];
//    this->_matrix = this->_matrix[elementCount][elementCount];
}

DSM::DSM(std::string elementNames[], int elementCount) {
    this->_elementCount=elementCount;
    this->_elementNames=new Vector<string>(this->_elementCount);
//    int** matrix = new int*[elementCount];
    this->_matrix = new int *[elementCount];
    for (int i = 0; i < elementCount; i++)
    {
        this->_matrix[i] = new int[elementCount];
    }
    for (int i = 0; i < elementCount; i++)
        for (int j = 0; j < elementCount; j++)
            this->_matrix[i][j] = 0;
    for (int i=0;i<this->_elementCount;i++){
        (this->_elementNames)->add(elementNames[i]);
    }
}

DSM::DSM(const DSM &other){
    this->_elementCount=other._elementCount;
    this->_elementNames=new Vector<string>(other._elementCount);
    for(int i=0;i<this->_elementCount;i++){
        this->_elementNames->add(other._elementNames->getElem(i));
    }
    this->_matrix=new int *[this->_elementCount];
    for (int i = 0; i < this->_elementCount; i++)
    {
        this->_matrix[i] = new int[this->_elementCount];
    }
   for(int i=0;i<this->_elementCount;i++){
       for(int j=0;j<this->_elementCount;j++){
           this->_matrix[i][j]=other._matrix[i][j];
       }
   }

}

void DSM::resizeMatrix(int n) {
    this->_elementCount=this->_elementCount+n;
    int** newMatrix=new int *[this->_elementCount];
    for (int i = 0; i < this->_elementCount; i++)
    {

        newMatrix[i] = new int[this->_elementCount];
    }
    for(int i=0;i<this->_elementCount;i++){
        for(int j=0;j<_elementCount;j++){
            newMatrix[i][j]=0;
        }
    }
    for(int i=0;i<this->_elementCount-n;i++){
        for(int j=0;j<this->_elementCount-n;j++){
            newMatrix[i][j]=this->_matrix[i][j];
        }
    }
    for (int i = 0; i < this->_elementCount-n; i++) {
        delete[] this->_matrix[i];
    }

    delete[] this->_matrix;
    this->_matrix=newMatrix;
//    delete[] newMatrix;

}

int DSM::size() const {
    return this->_elementCount;
}

void DSM::addLink(std::string fromElement, std::string toElement, int weight) {
    if(this->_elementNames->getIndex(toElement)==-1 && this->_elementNames->getIndex(fromElement)==-1){
        this->_elementNames->add(toElement);
        this->_elementNames->add(fromElement);
        this->resizeMatrix(2);
        this->_matrix[this->_elementNames->getIndex(fromElement)][this->_elementNames->getIndex(fromElement)]=weight;
    }
    else if(this->_elementNames->getIndex(toElement)==-1){
        this->_elementNames->add(toElement);
        this->resizeMatrix(1);
        this->_matrix[this->_elementCount-1][this->_elementNames->getIndex(fromElement)]=weight;
    }
    else if(this->_elementNames->getIndex(fromElement)==-1){
        this->_elementNames->add(fromElement);
        this->resizeMatrix(1);
        this->_matrix[this->_elementNames->getIndex(toElement)][this->_elementCount-1]=weight;
    }
    else{
        int fromIndex=(this->_elementNames)->getIndex(fromElement);
        int toIndex=(this->_elementNames)->getIndex(toElement);
        this->_matrix[toIndex][fromIndex]=weight;
    }
}

void DSM::deleteLink(std::string fromElement, std::string toElement) {
    int fromIndex=(this->_elementNames)->getIndex(fromElement);
    int toIndex=(this->_elementNames)->getIndex(toElement);
    this->_matrix[toIndex][fromIndex]=0;
}

bool DSM::hasLink(std::string fromElement, std::string toElement) {
    int fromIndex=(this->_elementNames)->getIndex(fromElement);
    int toIndex=(this->_elementNames)->getIndex(toElement);
    if(this->_matrix[toIndex][fromIndex]!=0){
        return true;
    }
    return false;
}

int DSM::linkWeight(std::string fromElement, std::string toElement) {
    int fromIndex=(this->_elementNames)->getIndex(fromElement);
    int toIndex=(this->_elementNames)->getIndex(toElement);
    return this->_matrix[toIndex][fromIndex];
}

int DSM::countToLinks(std::string elementName) {
    int index=(this->_elementNames)->getIndex(elementName);
    int count=0;
    for (int i=0;i<this->_elementCount;i++){
        if(this->_matrix[index][i]!=0){
            count++;
        }
    }
    return count;
}

int DSM::countFromLinks(std::string elementName) {
    int index=(this->_elementNames)->getIndex(elementName);
    int count=0;
    for (int i=0;i<this->_elementCount;i++){
        if(this->_matrix[i][index]!=0){
            count++;
        }
    }
    return count;
}

int DSM::countAllLinks() {
    int count=0;
    for (int i=0;i<this->_elementCount;i++){
        for(int j=0;j<this->_elementCount;j++){
            if(this->_matrix[i][j]!=0){
                count++;
            }
        }
    }
    return count;
}

void DSM::printMatrix() {
    for(int i=0;i<this->_elementCount;i++){
        for(int j=0;j<this->_elementCount;j++){
            cout<<this->_matrix[i][j]<<' ';
        }
        cout<<endl;
    }
}

DSM::~DSM() {
    delete this->_elementNames;
    for(int i=0;i<this->_elementCount;i++){
        delete[] this->_matrix[i];
    }
    delete[] this->_matrix;
}
