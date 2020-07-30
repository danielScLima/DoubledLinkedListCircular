#ifndef DOUBLED_LINKED_LIST_CIRCULAR_H
#define DOUBLED_LINKED_LIST_CIRCULAR_H

#include <iostream>
#include <vector>

/*!
 * \brief The DoubledLinkedCircularNode struct
 */
struct DoubledLinkedCircularNode
{
    /*!
     * \brief DoubledLinkedCircularNode
     */
    DoubledLinkedCircularNode()
    {
        next = nullptr;
        previous = nullptr;
        this->data = "";
    }
    /*!
     * \brief DoubledLinkedCircularNode
     * \param data
     */
    DoubledLinkedCircularNode(const std::string& data)
    {
        this->data = data;
        next = nullptr;
        previous = nullptr;
    }

    std::string data = "";
    struct DoubledLinkedCircularNode* next = nullptr;
    struct DoubledLinkedCircularNode* previous = nullptr;
};

/*!
 * \brief The DoubledLinkedListCircular class
 */
class DoubledLinkedListCircularDataStructure
{
public:
    /*!
     * \brief DoubledLinkedListCircularDataStructure
     */
    DoubledLinkedListCircularDataStructure();
    
    ~DoubledLinkedListCircularDataStructure();

    /*!
     * \brief insertBeforeStart
     * \param data
     */
    void insertBeforeStart(const std::string& data);
    /*!
     * \brief insertAfterStart
     * \param data
     */
    void insertAfterStart(const std::string& data);

    /*!
     * \brief removeBeforeStart
     * \return
     */
    DoubledLinkedCircularNode *removeBeforeStart();
    /*!
     * \brief removeAfterStart
     * \return
     */
    DoubledLinkedCircularNode *removeAfterStart();

    /*!
     * \brief getElementsAsVector
     * \return
     */
    std::vector<std::string> getElementsAsVector();

private:
    struct DoubledLinkedCircularNode* start = nullptr;
};

#endif // DOUBLED_LINKED_LIST_CIRCULAR_H
