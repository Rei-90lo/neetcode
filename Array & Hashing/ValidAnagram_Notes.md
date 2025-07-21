# Valid Anagram (有効なアナグラム) - 学習ノート

**問題リンク:** [https://neetcode.io/problems/is-anagram](https://neetcode.io/problems/is-anagram)

## 今回の学び (feat/fix/refactor)

*   **feat:** 
*   **fix:** 
*   **refactor:** 

---

## アプローチ1：ソートによる解法

2つの文字列をそれぞれソートし、結果が同じ文字列になるかどうかで判定する、最も直感的な方法。

*   **計算量:**
    *   時間計算量: `O(N log N)` (ソートがボトルネック)
    *   空間計算量: `O(1)` or `O(N)` (ソートの実装に依存)
*   **コード:**
    ```cpp
    #include <string>
    #include <algorithm>

    class Solution {
    public:
        bool isAnagram(std::string s, std::string t) {
            if (s.length() != t.length()) return false;
            std::sort(s.begin(), s.end());
            std::sort(t.begin(), t.end());
            return s == t;
        }
    };
    ```
*   **学び:**
    *   `std::sort(iterator first, iterator last)` は半開区間 `[first, last)` をソートする。
    *   `std::string` はイテレータ (`.begin()`, `.end()`) を持つため、`std::sort` で直接ソート可能。
    *   `std::sort` の戻り値は `void` で、元のコンテナを直接変更する（in-place）。

---

## アプローチ2：ハッシュマップによる解法

文字の出現回数をキーと値のペアで記録し、2つの文字列の文字数マップが等しいかで判定する方法。

*   **計算量:**
    *   時間計算量: `O(N + M)` (NとMは文字列長)。各文字列を1回ずつ走査するだけ。
    *   空間計算量: `O(K)` (Kは文字の種類数。最悪ケースで `O(N)`)
*   **コード:**
    ```cpp
    #include <string>
    #include <unordered_map>

    class Solution {
    public:
        bool isAnagram(std::string s, std::string t) {
            if (s.length() != t.length()) return false;
            std::unordered_map<char, int> sMap;
            for (char c : s) {
                sMap[c]++;
            }
            std::unordered_map<char, int> tMap;
            for (char c : t) {
                tMap[c]++;
            }
            return sMap == tMap;
        }
    };
    ```
*   **学び:**
    *   `std::unordered_map` はハッシュテーブルを基にした連想コンテナ。
    *   `map[key]++` は、キーが存在しない場合は自動で要素を作成し（値は0で初期化）、インクリメントしてくれるため、頻度カウントに非常に便利。
    *   `map` 同士は `==` で比較でき、キーと値のペアが全て一致する場合に `true` を返す。
    *   **`map` のメソッド比較:**
        | メソッド | 目的 | キーが存在しない時 | キーが存在する時 |
        | :--- | :--- | :--- | :--- |
        | `count(key)` | 存在チェック | `0`を返す | `1`を返す |
        | `insert({k,v})`| 新規追加 | 新しい要素 `{k,v}` を追加 | **何もしない** |
        | `operator[](key)`| アクセス/更新 | 新しい要素 `{k,0}` を作り、その参照を返す | 既存の値の参照を返す |

---

## アプローチ3：配列による最適化解法

問題の制約「英小文字のみ」を利用し、ハッシュマップの代わりに固定長の配列で頻度カウントを行う方法。

*   **計算量:**
    *   時間計算量: `O(N)` (Nは文字列長)。
    *   空間計算量: `O(1)` (文字セットのサイズは定数26のため)。
*   **コード:**
    ```cpp
    #include <string>
    #include <vector>

    class Solution {
    public:
        bool isAnagram(std::string s, std::string t) {
            if (s.length() != t.length()) return false;
            std::vector<int> counts(26, 0);
            for (char c : s) {
                counts[c - 'a']++;
            }
            for (char c : t) {
                counts[c - 'a']--;
            }
            for (int count : counts) {
                if (count != 0) {
                    return false;
                }
            }
            return true;
        }
    };
    ```
*   **学び:**
    *   問題の制約を最大限に活用することで、より効率的なデータ構造を選択できる。
    *   `char` 型は内部的には整数であり、`c - 'a'` のような計算でアルファベットを0からのインデックスに変換できる。
    *   この方法は、ハッシュ計算のオーバーヘッドがないため非常に高速。
