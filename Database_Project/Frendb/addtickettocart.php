<?php
  include 'config.php';
  session_start();
  $sql = "INSERT into ticketcart (user_id, ticket_id) values({$_SESSION['user_id']}, {$_GET['id']})";
  mysqli_query($con, $sql);
  header("Location: ticket.php");
?>
