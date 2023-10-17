#include <iostream>
#include <list>

// 병합 함수
void merge(std::list<std::pair<int, int>>& lst, std::list<std::pair<int, int>>::iterator left, std::list<std::pair<int, int>>::iterator mid, std::list<std::pair<int, int>>::iterator right) {
    std::list<std::pair<int, int>> leftList(left, mid);
    std::list<std::pair<int, int>> rightList(mid, right);

    auto it = left;
    auto leftIt = leftList.begin();
    auto rightIt = rightList.begin();

    while (leftIt != leftList.end() && rightIt != rightList.end()) {
        if (leftIt->first < rightIt->first) {
            *it++ = *leftIt++;
        } else {
            *it++ = *rightIt++;
        }
    }

    // 남은 원소들을 복사
    while (leftIt != leftList.end()) {
        *it++ = *leftIt++;
    }

    while (rightIt != rightList.end()) {
        *it++ = *rightIt++;
    }
}

// 병합 정렬 함수
void mergeSort(std::list<std::pair<int, int>>& lst) {
    if (lst.size() <= 1) {
        return;
    }

    // 중간 지점을 찾음
    auto mid = std::next(lst.begin(), lst.size() / 2);

    // 두 부분을 나누어 각각 정렬
    std::list<std::pair<int, int>> left(lst.begin(), mid);
    std::list<std::pair<int, int>> right(mid, lst.end());

    mergeSort(left);
    mergeSort(right);

    // 정렬된 두 부분을 병합
    merge(lst, lst.begin(), mid, lst.end());
}

int main() {
    // 정렬할 리스트 생성
    std::list<std::pair<int, int>> myList = {{3, 10}, {1, 5}, {2, 8}, {4, 3}};

    // 병합 정렬 수행
    mergeSort(myList);

    // 정렬된 결과 출력
    for (const auto& p : myList) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }

    return 0;
}
 