<?php
  include 'config.php';
  session_start();
  $sql = "UPDATE cart set cart_quantity = {$_GET['quantity']}
  where product_id = {$_GET['id']} && user_id = {$_SESSION['user_id']}";

  mysqli_query($con, $sql);
  header("Location: cart.php");
?>
