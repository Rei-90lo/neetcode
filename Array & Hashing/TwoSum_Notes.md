# Two Sum - 学習ノート

## 問題概要
整数の配列 `nums` と目標値 `target` が与えられたとき、`nums[i] + nums[j] == target` となる2つの要素のインデックス `[i, j]` を返す問題。

## アプローチ1: ブルートフォース (O(n^2))

### 考え方
二重ループを使って、配列内のすべての要素のペアをチェックする最も直感的な方法。

- 外側のループで要素 `nums[i]` を選択する。
- 内側のループで `nums[j]` (ただし `j > i`) を選択する。
- `nums[i] + nums[j]` が `target` と一致するかどうかを調べる。

### コード
```cpp
for(int i = 0; i < nums.size(); i++) {
    for(int j = i + 1; j < nums.size(); j++) {
        if(nums[i] + nums[j] == target) {
            return {i, j}; 
        }
    }
}
```

### 計算量
- 時間計算量: O(n^2) - `n`個の要素に対して二重ループを実行するため。
- 空間計算量: O(1) - 追加のデータ構造を使用しないため。

## アプローチ2: ハッシュマップ (O(n))

### 考え方
計算量をO(n)に改善するために、ハッシュマップ（C++では `std::unordered_map`）を利用する。ループを1回に抑えるのが目標。

1. `数値` をキー、`インデックス` を値とするハッシュマップを用意する。
2. 配列 `nums` を一度だけループする。
3. 各要素 `nums[i]` について、`complement = target - nums[i]` を計算する。
4. この `complement` がハッシュマップのキーとして既に存在するかを調べる。
    - **存在する場合**: `complement` のインデックスと現在のインデックス `i` が求めるペア。
    - **存在しない場合**: 現在の `nums[i]` とそのインデックス `i` をハッシュマップに保存する。

これにより、各要素について、その相方（complement）が過去に現れたかどうかを O(1) で高速に検索できる。

### 完成したコード (最終版)
```cpp
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        for(int i = 0; i < nums.size(); i++){
            // target との差分 (complement) を計算
            int complement = target - nums[i];
            
            // complement がマップに存在するかチェック
            if(numMap.count(complement)) {
                // 存在すれば、そのインデックスと現在のインデックスを返す
                return {numMap[complement], i};
            }
            
            // 存在しなければ、現在の数値とインデックスをマップに追加
            numMap[nums[i]] = i;
        }
        return {}; // 解が見つからない場合
    }
};
```
*注: `find`の代わりに`count`を使うと、コードがより簡潔になる場合があります。`count`はキーが存在すれば1、しなければ0を返します。`find`と`!= .end()`の比較でも同じ結果が得られます。*

## 今回の学び (fix)
- **`fix`: C++の `std::unordered_map::find` メソッドは、キーが見つからない場合に `map.end()` という特別なイテレータ（反復子）を返す。そのため、キーの存在確認は `map.find(key) != map.end()` のように比較する必要があることを理解した。**
