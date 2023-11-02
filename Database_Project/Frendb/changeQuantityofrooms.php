<?php
  include 'config.php';
  session_start();
  $sql = "UPDATE hotelcart set room_quantity = {$_GET['quantity']}
  where hotel_id = {$_GET['id']} && user_id = {$_SESSION['user_id']}";

  mysqli_query($con, $sql);
  header("Location: hotelcart.php");
?>
