# Breadth-first search

---

BFS là một thuật toán đơn giản và phổ biến trong lí thuyết đồ thị.

Con đường được tìm bởi BFS tới tất cả các node là con đường ngắn nhất (shortest path) trong đồ thị không trọng sô.

Độ phức tạp O(n+m)

## Thuật toán.

Đi từ đỉnh gốc là s lan truyền thuận qua các đỉnh kề cận s nếu nó chưa được truyền tới, nếu tất cả đều được truyền dừng và kết thúc thuật toán.

Thuật toán giống như hiệu ứng cháy nhà "ring of fire", ban đầu chỉ có nhà s bị cháy sau đó lan rộng ra các tòa nhà xung quanh trong cùng 1 thời điểm.

## Applications 

1. Tim đường đi ngắn nhất trong đồ thị không trọng số.

1. Tìm tất cả connected components trong đồ thị không trọng số O(n+m)

1. Giải quyết các bài toán với số lượng bước đi là nhỏ nhất ( Lí thuyết trò chơi ....)

1. Tìm đường đi ngắn nhất trong đồ thị trọng số nhị phân (0,1) trong O(n+c*m) trong đó c là constant < 4. Nếu cạnh hiện tại có trọng số là 0 và khoảng cách tới đỉnh đó là bé hơn so với khoảng cách hiện tại ta sẽ đưa đỉnh đó vào đầu của queue. **DijstraFake**

1. Tim đường đi vòng (Euler) ngắn nhất trong đồ thị không trọng số. Ta sẽ duyệt tới khi gặp 1 chu trình và ta lấy hết chu trình đó sau đó tiếp tục bfs tại đỉnh hiện tại.

1. Kiểm tra xem cạnh uv có nằm trên đường đi ngắn nhất từ đỉnh a tới đỉnh b hay không. Chạy bfs từ đỉnh a nếu uv là 1 cạnh có thể nằm trên đường đi khi và chỉ khỉ d_a[u]+1+d_b[v]=d_a[b]

1. Tim đường đi ngắn nhất với số cạnh là chẵn hoặc lẻ.

---

# Depth First Search

DFS là 1 trong nhưng thuật toán chủ đạo của lí thuyết đồ thị.

DFS tìm đường đi với đỉnh tuân theo thứ tự từ điển **lexicographical**.

Độ phức tạp O(n+m).

## Description 

Ý tưởng DFS là đi từ 1 đỉnh và đi sâu nhất có thể sau đó quai ngược về các đỉnh khác.

## Applications 

1. Tìm bất kì đường đi nào từ đỉnh u tới mọi đỉnh.

1. Tìm đường đi có thứ tự từ điển ngắn nhất.

1. Tìm cha chung gần nhất (LCA) giữa 2 đỉnh.

1. Topological sorting

1. Tìm thành phần liên thông mạnh trong đồ thị có hướng.

1. Tìm khớp và cầu trong đồ thị có/vô hướng.

1. Phân loại cạnh trong đồ thị.



