<?php
  include 'config.php';
  session_start();
  $sql = "UPDATE ticketcart set ticket_quantity = {$_GET['quantity']}
  where ticket_id = {$_GET['id']} && user_id = {$_SESSION['user_id']}";

  mysqli_query($con, $sql);
  header("Location: ticketcart.php");
?>
