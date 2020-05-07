# Connected components, bridges, articulations points

---


## Thành Phần liên thông mạnh của đồ thị vô hướng.

Sử dụng bfs/dfs để truy vấn lần nước các thành phần liên thông.

Độ phức tap O(n+m)


---


## Tìm Khớp-cầu trong đồ thị  

Định nghĩa 1 cạnh được gọi là cầu nếu bỏ cạnh đó đi thì số thành phần liên thông tăng lên.

Lưu ý bài toán tìm cầu online/ofline là 2 bài toán hoàn toàn khác nhau dưới đấy trình bày giải thuật tìm cầu offline trong thời gian O(n+m)

### Algorithm

Chọn 1 đỉnh trong đồ thị và dfs từ đỉnh đó.Dễ dàng chứng minh được:

> Giả sử chúng ta đang trên cây dfs bắt đầu từ đỉnh u, và đỉnh hiện tại là v. Ta xét các cạnh (v,to) là cầu khi và chỉ khi không tồn tại bất kì cung ngược nào từ to tới đỉnh v hoặc bất kì cha chung trên cây dfs của v. Điều đó có nghĩa là sẽ không thể đi từ v tới to nếu bỏ cạnh (v,to).

Chúng ta sẽ sử dụng kĩ thuật đường truyền, tại mỗi bước dfs lưu 2 giá trị trên mỗi đỉnh. 

* Nun(u) là  thời gian dfs đạt tới đỉnh u

* low(u) là độ sâu thấp nhất có thể của u

Ta có :

1. low(u) <= Num(u)
2. low(u) =min(low(u),num(p)) nếu p là đỉnh đã được duyệt trươc đó.(backedge)
3. low(u)=min(low(u),low(to)) nếu to chưa được duyệt và có 1 cạnh (u,to)

Sau cùng nếu low(to)>num(v) thì cạnh (u,v) là cầu.


Ta có thể chứng minh tượng tự, đỉnh u được gọi là khớp khi và chỉ khi tồn tại cạnh (u,v) trong đồ thị và low(to) > num(u) hoặc low(to)>=num(u) && (nếu u là root thì u phải có nhiều hơn 1 cây con).

