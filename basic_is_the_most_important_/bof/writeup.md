![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/14bee83c02e8c277ee2bbb5e218993a78649233fc387892db08b10645f3423f7.png)

**가장 먼저, admin 계정의 탈취된 비번을 찾아야한다.**
각 파일들이 무슨 역할을 하는지 간단하게 알아보고 가자.

## board.php
유심히 봐야할 부분은 <?php...부분이다.
param 중 search가 set되어있다면,

```php
if(isset($_GET['search'])){
        $search = mysqli_real_escape_string($conn, $_GET['search']);
        $sql .= "Where title like '%${search}%' ";
      }
```

글 제목 중 search가 포함된 게시글을 가져와 사용자에게 보여준다.

또한,
```php
 if(isset($_GET['sort']) && $_GET['sort'] != "" ){
        $sql .= "order by ". $_GET['sort']; 
      }else{
        $sql .= "order by idx asc";
      }
```
sort라는 param이 주어진다면 그 sort값을 기준으로 정렬한다.
기본값은 **ASC**(idx 기준 오름차순)이다.

그 밑 부분은 일반 게시판 서비스처럼, 게시글 작성자, 제목, 내용을 가져오는 역할을 한다.
물론, 로그인이 되어있지 않은 경우에는 로그인을 하게 한다.

## login.php
```
<html>
<head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.2/css/bootstrap.min.css">
<title>Simple Board</title>
</head>
<body>
    <!-- Fixed navbar -->
    <nav class="navbar navbar-default navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <a class="navbar-brand" href="/">Simple Board</a>
        </div>
        <div id="navbar">
          <ul class="nav navbar-nav">
            <li><a href="/">Home</a></li>
            <li><a href="/board.php">Board</a></li>
            <?php 
              include "./config.php";
              if(isset($_SESSION['username'])){
            ?>
            <li><a href="/logout.php">Logout</a></li> 
            <?php
            }else{
            ?>
            <li><a href="/login.php">Login</a></li>
            <?php              
            }
            ?>
          </ul>

        </div><!--/.nav-collapse -->
      </div>
    </nav><br/><br/><br/>
    <div class="container">
      <ul>
    <?php
      if ($_SERVER['REQUEST_METHOD'] === 'GET') {
    ?>
      <form method="POST">
        <div class="form-group">
          <label for="username">username</label>
          <input type="text" class="form-control" name="username" id="username" placeholder="username">
        </div>
        <div class="form-group">
          <label for="passowrd">암호</label>
          <input type="password" class="form-control" name="password" id="password" placeholder="password">
        </div>
        <button type="submit" class="btn btn-default">Login</button>
      </form>
    <?php
      }elseif($_SERVER['REQUEST_METHOD'] === 'POST'){
        $conn = dbconn();
        if(isset($_POST['username']) && isset($_POST['password'])){
          $username = mysqli_real_escape_string($conn, $_POST['username']);
          $password = mysqli_real_escape_string($conn, $_POST['password']);
          $sql = "SELECT * FROM users WHERE username='${username}' and password='${password}'";
          $result = mysqli_query($conn, $sql) or die(error(500));
          $row = mysqli_fetch_array($result);
          if($row['username'] === $username && $row['password'] === $password ){
            $_SESSION['username'] = $row['username'];
            $_SESSION['level'] = $row['level'];
            die("<h2>Login Success !</h2>");
          }
        }
        die("<h2>Login Fail !</h2>");
      }
      
    ?> 
    </ul></div> 
</body>
</html>
```
우리가 입력한 유저이름과 비번은
`username`과 `password` 라는 컬럼에 저장된다는 것을 확인 가능하다.

## config.php

**유심히 봐야할 부분은 두 군데이다.**
```
$level = array(
	0 => "admin",
	1 => "guest"
);
```
권한을 구분하는 부분이다.
0은 관리자, 1은 게스트를 의미한다.

`$upload_dir = "./uploads/";`
이 부분은 우리가 업로드한 파일들이 어디 저장될지를 알려준다.
전형적인 설정 파일임을 알 수 있다.

이쯤 왔으면 한 번 생각해볼 수 있다.
### *board.php에서 param값을 검증했음?*

```php
if(isset($_GET['search'])){
        $search = mysqli_real_escape_string($conn, $_GET['search']);
        $sql .= "Where title like '%${search}%' ";
      }
      if(isset($_GET['sort']) && $_GET['sort'] != "" ){
        $sql .= "order by ". $_GET['sort']; 
      }else{
        $sql .= "order by idx asc";
      }

```
역시나, 값을 전혀 검증하지 않는다.

그렇다면 공격자는 여기서 injection을 시도해봤는지 로그를 확인해보자.
비번을 봐야 하니, `substr`, `select`, 또한 `union` 등의 query를 사용했을 것 같다.

![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/727fadeb2051cbc73a64f77e730a34b6a1680ca38ae8545aaaa41df06ce2ff6e.png)

역시, 우리의 예상이 맞았다.
당연히 비번을 한 글자씩 돌아가면서 맞췄을 것이다.
구체적으로, `username, password, select, substr`
이 구문을 사용하여 돌아다녔던 흔적을 찾아보자.


![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/f473c8c84a2040c7aacd3fb632ed46e51693468a75205778ca27e4cc926f971d.png)

# 찾았다.

보면 거의 다 응답 결과가 200이며, 응답 길이가 841이다.
**그런데...**

![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/ee311fa3deb583b174fe9f4aba5484fc67fcf0ccae6b4f671b169f9d480209ae.png)

어디선가 갑자기 응답길이의 수가 변한다?!
이를 통해 우리는 **비번의 n번째 자리를 맞혔을 때의 응답 길이가 1192임을** 유추해 볼 수 있다.

substr((select%20group_concat(username,0x3a,password)%20from%20users가 포함되면서
응답 길이가 1192자인 로그를 모으면 된다.
시간상의 기록들을 참조했을 때, 이는 사람의 손으로 한 것이 아닌 자동화를 통해 비번을 유추하려 시도했던 것을 검증할 수 있다.

그러므로, 차례대로, substr...=97부터 시작하여 모으면 아래와 같은 list를 만들 수 있다.
_ = ['97','100','109','105','110','58',...'116']
아스키코드를 모았으니, 이를 변환하면 된다.

여기서는 **Python**을 사용하겠다.

```python
pw = ["97","100","109","105","110","58","84","104","49","115","95","49","115","95","65","100","109","49","110","95","80","64","83","83","44","103","117","101","115","116","58","103","117","101","115","116"]

for i in range(len(pw)):
    print(chr(int(pw[i])), end="")

```
![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/3ea34bded90ba175b91c48060bae739970880654b384056977b3c4593d089d1a.png)

admin: 어드민 비번,guest: 게스트비번
key value 형식으로 잘 나오는 것을 확인 가능하다.

![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/58ee70aef1394c12bcb88ad7a30769b0c8fe232f902a03f06a396f3f9b0b9693.png)

level1부터는 간략하게 설명하도록 하겠다.

![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/d2490c4336e132b1468ddf40af4f20c86909104d88777e42387bd5d69c86ef22.png)

config.php에 접근한 흔적을 찾아보면
여러개가 나온다. 하지만 마지막에...
![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/56968ddbe056d57bf14a524d12ae9b4da9434b41836580fbf719acc7b4dc1444.png)
이런 식으로 php 코드를 추출했다는 것을 알 수 있다.
`GET /admin/?page=php://filter/convert.base64-encode/resource=../config.php HTTP/1.1`
php:// ... ../config.php <<<----- 이 부분을 복사하여 제출하면,

![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/b5a7a7cfe62e440aa9a29e18d40ac3237342257a34235094da9e4e4f51f02bfa.png)




