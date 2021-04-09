## TODO

`query()` を交換則が成り立たなくても OK な感じにする

## 説明

- `HeavyLightDecomposition(g)`: 木 $g$ で初期化
- `build(r)`: 頂点 $r$ を根として構築
- `lca(u, v)`: $u,v$ の最近共通祖先 $(\mathrm{LCA})$ を返す

## 計算量

`query`, `add` に渡される関数は $O(1)$ と仮定する

- constructor: $O(n)$
- `build`: $O(n)$
- クエリ: $O(\log n)$