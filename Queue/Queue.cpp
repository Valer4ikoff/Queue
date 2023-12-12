/*1, Дано рядок s, знайти в ньому перший 
неповторюваний символ і повернути його індекс. Якщо його не існує, поверніть -1.*/




/*

#include <iostream>
#include <unordered_map>

int firstUniqChar(const std::string& s) {
    std::unordered_map<char, int> charCount;

    // Рахуємо кількість кожного символу в рядку
    for (char ch : s) {
        charCount[ch]++;
    }

    // Знаходимо перший неповторюваний символ
    for (int i = 0; i < s.length(); ++i) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }

    return -1; // Неповторюваний символ не знайдено
}

int main() {
    // Приклади використання
    std::string example1 = "leopard";
    std::string example2 = "loveleopard";
    std::string example3 = "aabb";

    std::cout << "Example 1: " << firstUniqChar(example1) << std::endl;
    std::cout << "Example 2: " << firstUniqChar(example2) << std::endl;
    std::cout << "Example 3: " << firstUniqChar(example3) << std::endl;

    return 0;
}



*/





/*2, Реалізуйте стек «останній прийшов першим вийшов» (LIFO), використовуючи лише дві черги. 
Реалізований стек повинен підтримувати всі функції звичайного стека (push, top, pop і empty).*/



/*

#include <iostream>
#include <queue>

class MyStack {
public:
    MyStack() {}

    void push(int x) {
        // Додаємо елемент на вершину першої черги
        q1.push(x);

        // Переміщаємо всі елементи з другої черги в першу
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        // Переставляємо q1 і q2, щоб зберегти порядок додавання елементів
        std::swap(q1, q2);
    }

    int pop() {
        // Видаляємо та повертаємо верхній елемент з першої черги
        int topElement = q2.front();
        q2.pop();
        return topElement;
    }

    int top() {
        // Повертаємо верхній елемент першої черги, не видаляючи його
        return q2.front();
    }

    bool empty() {
        // Перевіряємо, чи обидві черги порожні
        return q1.empty() && q2.empty();
    }

private:
    std::queue<int> q1, q2;
};

int main() {
    // Приклад використання
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    std::cout << "Top: " << myStack.top() << std::endl; // повинно вивести 2
    std::cout << "Pop: " << myStack.pop() << std::endl; // повинно вивести 2
    std::cout << "Is Empty: " << (myStack.empty() ? "true" : "false") << std::endl; // повинно вивести false

    return 0;
}



*/





/*3, У вас є клас RecentCounter, який підраховує кількість останніх запитів протягом певного періоду часу.*/



/*


#include <queue>

class RecentCounter {
public:
    RecentCounter() {}

    int ping(int t) {
        // Додаємо новий запит у чергу
        requests.push(t);

        // Видаляємо запити, які виходять за межі 3000 мілісекунд
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        // Повертаємо кількість запитів за останні 3000 мілісекунд
        return requests.size();
    }

private:
    std::queue<int> requests;
};

int main() {
    RecentCounter recentCounter;
    // Приклад використання
    printf("%d\n", recentCounter.ping(1)); // повинно вивести 1
    printf("%d\n", recentCounter.ping(100)); // повинно вивести 2
    printf("%d\n", recentCounter.ping(3001)); // повинно вивести 3
    printf("%d\n", recentCounter.ping(3002)); // повинно вивести 3

    return 0;
}


*/




 
/*6, Вам надано масив цілих чисел nums, є ковзаюче вікно розміром k, яке рухається з самого лівого 
краю масиву до самого правого. 
Ви можете побачити лише k чисел у вікні. Щоразу ковзне вікно переміщується на одну позицію праворуч.*/



/*

#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::deque<int> dq;

    for (int i = 0; i < nums.size(); ++i) {
        // Видаляємо з кінця елементи, що вже не відносяться до поточного вікна
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Видаляємо з кінця елементи, менші за поточний елемент nums[i]
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Додаємо поточний індекс до кінця deque
        dq.push_back(i);

        // Додаємо максимум вікна до результату
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    std::vector<int> result1 = maxSlidingWindow(nums1, k1);

    std::cout << "Output 1: [";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    std::vector<int> nums2 = {1};
    int k2 = 1;
    std::vector<int> result2 = maxSlidingWindow(nums2, k2);

    std::cout << "Output 2: [";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}


*/




/*7, Дано цілий масив nums і ціле k, повернути максимальну суму непорожньої підпослідовності цього
масиву так, що для кожних двох послідовних цілих чисел у підпослідовності, 
nums[i] і nums[j], де i < j, умова j - i <= k виконується.*/





/*

#include <iostream>
#include <vector>
#include <algorithm>

int maxSumAfterKOperations(const std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> dp(n, 0);
    int maxSum = nums[0];

    for (int i = 0; i < n; ++i) {
        dp[i] = nums[i];
        maxSum = std::max(maxSum, dp[i]);

        for (int j = std::max(0, i - k); j < i; ++j) {
            dp[i] = std::max(dp[i], dp[j] + nums[i]);
            maxSum = std::max(maxSum, dp[i]);
        }
    }

    return maxSum;
}

int main() {
    std::vector<int> nums1 = {10, 2, -10, 5, 20};
    int k1 = 2;
    int result1 = maxSumAfterKOperations(nums1, k1);

    std::cout << "Output 1: " << result1 << std::endl;

    std::vector<int> nums2 = {-1, -2, -3};
    int k2 = 1;
    int result2 = maxSumAfterKOperations(nums2, k2);

    std::cout << "Output 2: " << result2 << std::endl;

    std::vector<int> nums3 = {10, -2, -10, -5, 20};
    int k3 = 2;
    int result3 = maxSumAfterKOperations(nums3, k3);

    std::cout << "Output 3: " << result3 << std::endl;

    return 0;
}


*/