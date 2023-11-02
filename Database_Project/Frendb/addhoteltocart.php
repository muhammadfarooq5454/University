<?php
  include 'config.php';
  session_start();
  $sql = "INSERT into hotelcart (user_id, hotel_id) values({$_SESSION['user_id']}, {$_GET['id']})";
  mysqli_query($con, $sql);
  header("Location: hotel.php");
?>
