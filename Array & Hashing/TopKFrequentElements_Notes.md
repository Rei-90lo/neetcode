# 問題: Top K Frequent Elements (出現頻度上位K個の要素)

## この問題の目的
整数の配列 `nums` と整数 `k` が与えられます。配列の中で**最も頻繁に出現する要素（数値）を、上位 `k` 個**見つけて返す問題です。答えの順序は問いません。

**例:**
`nums = [1, 2, 2, 3, 3, 3]`, `k = 2` の場合
- `3` は3回出現
- `2` は2回出現
- `1` は1回出現
出現頻度の上位2つは `3` と `2` なので、答えは `[3, 2]` や `[2, 3]` となります。

---

## 解法1：ハッシュマップとソート (計算量: O(n log n))
この方法は、実装が直感的で分かりやすいです。

### 手順
1.  **出現回数を数える**: `std::unordered_map<int, int>` を使い、各数値が何回出現したかを記録します。
    ```cpp
    std::unordered_map<int, int> counter;
    for(int n : nums) {
        counter[n]++;
    }
    ```
2.  **ソートのためにベクターにコピーする**: `std::unordered_map` は直接ソートできません。これは、`std::sort` が要求する「ランダムアクセスイテレータ」をマップが持っていないためです。そのため、マップの中身を `std::vector<std::pair<int, int>>` にコピーします。
    ```cpp
    std::vector<std::pair<int, int>> vec(counter.begin(), counter.end());
    ```
3.  **ベクターをソートする**: 出現回数（`pair`の2番目の要素）を基準に、**降順（大きい順）**でソートします。`std::sort` にカスタム比較関数（ラムダ式）を渡すことで実現できます。
    ```cpp
    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // 2番目の要素（出現回数）で降順ソート
    });
    ```
4.  **結果を取り出す**: ソートされたベクターの先頭から `k` 個の要素のキー（元の数値）を取り出します。
    ```cpp
    std::vector<int> result;
    for(int i = 0; i < k; i++) {
        result.push_back(vec[i].first);
    }
    return result;
    ```

---

## 解法2：バケットソート (計算量: O(n))
この問題で期待されている、より効率的な解法です。

### 手順
1.  **出現回数を数える**: 解法1と同様に `std::unordered_map` を使います。
2.  **バケットを用意する**: 「バケット（bucket）」として、`std::vector<std::vector<int>>` を用意します。
    -   `freq` の**インデックス**が**出現回数**に対応します。
    -   `freq` の**各要素**が、その出現回数を持つ**数値のリスト** (`vector<int>`) になります。
    - `vector<vector<int>>` を使う理由は、同じ出現回数を持つ数値が複数存在する可能性があるためです。（例：`freq[3]` には、3回出現した数値をすべて格納する必要があります）
    ```cpp
    // 配列のサイズ+1で、インデックスと出現回数を一致させる
    std::vector<std::vector<int>> freq(nums.size() + 1);
    for (const auto& entry : counter) {
        // entry.second は出現回数, entry.first は数値
        freq[entry.second].push_back(entry.first);
    }
    ```
3.  **結果を取り出す**: バケットを**後ろから**（つまり出現回数が多い方から）見ていき、結果ベクターのサイズが `k` になるまで要素を追加します。
    ```cpp
    std::vector<int> result;
    for (int i = freq.size() - 1; i > 0; --i) {
        for (int n : freq[i]) {
            result.push_back(n);
            if (result.size() == k) {
                return result;
            }
        }
    }
    return result;
    ```

---

## 関連するC++の知識

-   **`std::vector`への要素追加**:
    -   `push_back()`: ベクターの**末尾**に要素を追加します。
    -   `insert()`: ベクターの**途中**（指定した位置）に要素を挿入します。
-   **`std::sort`のカスタム比較**: 第3引数に比較用の関数（ラムダ式が便利）を渡すことで、昇順以外の好きな順序でソートできます。
