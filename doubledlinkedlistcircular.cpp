#include "doubledlinkedlistcircular.h"

DoubledLinkedListCircular::DoubledLinkedListCircular()
{

}

DoubledLinkedListCircular::~DoubledLinkedListCircular()
{
    DoubledLinkedCircularNode* initialHead = start;
    if (initialHead != nullptr)
    {
        DoubledLinkedCircularNode* tmp = initialHead->next;
        delete initialHead;
        while (tmp != initialHead)
        {
            start = tmp->next;
            delete tmp;
            tmp = start;
        }
    }
}

void DoubledLinkedListCircular::insertBeforeStart(const std::string& data)
{
    struct DoubledLinkedCircularNode* tmp = new DoubledLinkedCircularNode(data);

    if (start == nullptr)
    {
        start = tmp;
        start->next = start;
        start->previous = start;
    }
    else
    {
        DoubledLinkedCircularNode* previousStart = start->previous;
        tmp->next = start;
        tmp->previous = previousStart;

        start->previous = tmp;
        previousStart->next = tmp;
    }
}

void DoubledLinkedListCircular::insertAfterStart(const std::string& data)
{
    struct DoubledLinkedCircularNode* tmp = new DoubledLinkedCircularNode(data);

    if (start == nullptr)
    {
        start = tmp;
        start->next = start;
        start->previous = start;
    }
    else
    {
        DoubledLinkedCircularNode* nextStart = start->next;

        tmp->next = nextStart;
        tmp->previous = start;

        start->next = tmp;
        nextStart->previous = tmp;
    }
}

DoubledLinkedCircularNode *DoubledLinkedListCircular::removeBeforeStart()
{
    if (start == nullptr)
        return nullptr;
    else
    {
        if (start->next == start)
        {
            DoubledLinkedCircularNode *tmp = start;
            start = nullptr;
            return tmp;
        }
        else
        {
            DoubledLinkedCircularNode *tmp = start->previous;
            DoubledLinkedCircularNode *beforeTmp = tmp->previous;

            beforeTmp->next = start;
            start->previous = beforeTmp;

            return tmp;
        }
    }
}

DoubledLinkedCircularNode *DoubledLinkedListCircular::removeAfterStart()
{
    if (start == nullptr)
        return nullptr;
    else
    {
        if (start->next == start)
        {
            DoubledLinkedCircularNode *tmp = start;
            start = nullptr;
            return tmp;
        }
        else
        {
            DoubledLinkedCircularNode *tmp = start->next;
            DoubledLinkedCircularNode *afterTmp = tmp->next;

            start->next = afterTmp;
            afterTmp->previous = start;

            return tmp;
        }
    }
}

std::vector<std::string> DoubledLinkedListCircular::getElementsAsVector()
{
    std::vector<std::string> vec;

    if (start != nullptr)
    {
        vec.push_back(start->data);

        if (start->next != nullptr)
        {
            DoubledLinkedCircularNode* tmp = start->next;
            while (tmp != start)
            {
                vec.push_back(tmp->data);
                tmp = tmp->next;
            }
        }
    }

    return vec;
}
