# Lee's Journey

## I, Hướng dẫn cài đặt và chạy game
  ### B1: Tải project về
  Cách 1: Trên Github, chọn Code => Download ZIP  
  Cách 2: Mở terminal tại thư mục muốn lưu project, sử dụng lệnh `git init` để khởi tạo Git, sau đó dùng lệnh `git clone https://github.com/ThuanLee/Lee_Journey.git` để clone project về máy  
  ### B2: Cài đặt Make
  Tải và cài đặt Make từ đường link sau: [(http://gnuwin32.sourceforge.net/packages/make.htm)](http://gnuwin32.sourceforge.net/packages/make.htm)  
  Thêm đường dẫn đến thư mục chứa file make.exe vào `environment variable`
  VD: C:\Program Files (x86)\GnuWin32\bin 
  ### B3: Build project
  Mở terminal tại thư mục chứa project, sử dụng lệnh `make` để build  
  ### B4: Hoàn tất
  Giờ chỉ cần nhấn đúp vào file .exe vừa được tạo ra để chạy game  
  
## II, Mô tả chung về trò chơi
  **Thể loại:** `Sinh tồn`, `Platform`, `Tính điẻm theo thời gian thực`  
  **Cốt truyện:** Trong Lee's Journey, bạn được nhập vai vào chàng hiệp sĩ Lee trên con đường giải cứu thế giới. Nhiệm vụ của bạn là né tránh các đợt tấn công bằng thiên thạch của những tên pháp sư Trunghoa để sống sót được lâu nhất trước khi chúng cạn Mana.  
  **Ý tưởng:** Dựa trên những game sinh tồn Endless như Dino, Flappy Bird, Temple run,...  

### III, Các chức năng của trò chơi
  - Menu đơn giản
  - Điều khiển nhân vật bằng các phím `W`, `A`, `S`, `D` và `Space`
  - Có bộ tính điểm
  - Độ khó tăng dần theo thời gian
  - Có theme song và một số sound effect
    
### IV, Các kỹ thuật lập trình được sử dụng
  - Sử dụng thư viện đồ họa SFML
  - Lập trình hướng đối tượng (class)
  - Con trỏ, cấp phát động
  - Sử dụng thuật toán xử lý va chạm AABB  

### V, Kết luận
  Do là dự án game đầu tay nên không thể tránh khỏi các thiếu xót, mong rằng sẽ nhận được góp ý từ mọi người. Mình sẽ update các bản vá lỗi để game được hoàn thiện       hơn.  
  
  Hướng phát triển tiếp theo của game dự kiến sẽ là:
  - Thêm hệ thống Highscore
  - Thêm tính năng lưu trữ tiến độ chơi khi Exit giữa chừng
  - Thêm các màn chơi khác nhau để tránh nhàm chán
  - Thêm hệ thống combat với quái và pickup item ngẫu nhiên trên map  
 
Sau khi hoàn thiện chương trình, thứ em tâm đắc nhất trước hết là kinh nghiệm quản lý một project lớn, cách chia nhỏ từng file, từng class sao cho dễ sửa đổi, nâng  cấp. Tiếp sau đó là kinh nghiệm lập trình hướng đối tượng - kiến thức được áp dụng trong suốt quá trình làm game của em. Và cuối cùng là việc làm game đã tiếp thêm niềm đam mê lập trình cho bản thân em vì nó không khô khan như việc học thuật toán để giải các bài toán khó.
