/*
 * There is a queue for the self-checkout tills at the supermarket. 
 * Your task is write a function to calculate the total time required for all the customers to check out!
 * The function has two input variables:

 * customers: an array (list in python) of positive integers representing the queue. 
 * Each integer represents a customer, and its value is the amount of time they require to check out.
 * n: a positive integer, the number of checkout tills.
 * The function should return an integer, the total time required.
 * 
 * EDIT: A lot of people have been confused in the comments. To try to prevent any more confusion:
 * 
 * There is only ONE queue, and
 * The order of the queue NEVER changes, and
 * Assume that the front person in the queue (i.e. the first element in the array/list) proceeds to a till as soon as it becomes free.
 * The diagram on the wiki page I linked to at the bottom of the description may be useful.
 * So, for example:
 * 
 * queueTime(std::vector<int>{5,3,4}, 1)
 * // should return 12
 * // because when n=1, the total time is just the sum of the times
 * 
 * queueTime(std::vector<int>{10,2,3,3}, 2)
 * // should return 10
 * // because here n=2 and the 2nd, 3rd, and 4th people in the 
 * // queue finish before the 1st person has finished.
 * 
 * queueTime(std::vector<int>{2,3,10}, 2)
 * // should return 12
 *  
 * Copied from: https://www.codewars.com/kata/the-supermarket-queue/cpp
 */

#include <vector>
#include <cassert>

std::vector<int> get_n_customer(std::vector<int> &queue, int n)
{
    std::vector<int> the_chosen;

    std::vector<int>::iterator it;

    for (int i = 0; i < n && queue.size() > 0; i++)
    {
        it = queue.begin();

        the_chosen.push_back(*it);

        queue.erase(it);
    }

    return the_chosen;
}

int get_the_next_available_customer(std::vector<int> &queue)
{
    int customer;
    std::vector<int>::iterator it = queue.begin();

    customer = *it;

    queue.erase(it);

    return customer;
}

long queueTime(std::vector<int> customers, int n)
{
    long result = 0;

    if (customers.size() == 0)
    {
        return 0;
    }

    std::vector<int> queue = customers;

    std::vector<int> the_chosen = get_n_customer(queue, n);

    while (true)
    {
        for (int i = 0; i < the_chosen.size(); i++)
        {
            if (the_chosen[i] > 0)
            {
                the_chosen[i]--;
            }
        }
        for (int i = 0; i < the_chosen.size(); i++)
        {
            if (the_chosen[i] == 0 && queue.size() > 0)
            {
                the_chosen[i] = get_the_next_available_customer(queue);
            }
        }

        result++;
        int sum = 0;
        for (int i = 0; i < the_chosen.size(); i++)
        {
            sum += the_chosen[i];
        }
        if (sum == 0)
        {
            break;
        }
    }

    return result;
}

int main()
{
    assert(queueTime(std::vector<int>{}, 1) == 0);
    assert(queueTime(std::vector<int>{5, 3, 4}, 1) == 12);
    assert(queueTime(std::vector<int>{10, 2, 3, 3}, 2) == 10);
    assert(queueTime(std::vector<int>{2, 3, 10}, 2) == 12);
    assert(queueTime(std::vector<int>{2, 3, 10}, 100) == 10);

    return 0;
}