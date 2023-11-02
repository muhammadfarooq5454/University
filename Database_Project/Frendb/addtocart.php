<?php
  include 'config.php';
  session_start();
  $sql = "INSERT into cart (user_id, product_id) values({$_SESSION['user_id']}, {$_GET['id']})";

  mysqli_query($con, $sql);
  header("Location: product.php");
?>
