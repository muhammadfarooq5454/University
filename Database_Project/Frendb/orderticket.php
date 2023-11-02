<!DOCTYPE html>
<html>
<head>
  <title>orderhotel</title>
  <link rel="stylesheet" type="text/css" href="stylingoforder.css">
</head>
<body>
  <?php include 'header.php'?>;
</body>
</html>

<?php

include 'config.php';

session_start();

$querry ="SELECT * FROM ticketcart c inner join ticket t on t.ticketid = c.ticket_id where c.user_id = {$_SESSION['user_id']} order by t.ticketid ASC";
$result = mysqli_query($con,$querry);

$num=mysqli_num_rows($result);

$priceSum = 0;

if($num>0)
{
  while($tkt=mysqli_fetch_array($result))
  {
    $priceSum += $tkt['price']*$tkt['ticket_quantity'];
  }
}

$querry ="SELECT * FROM users where user_id = {$_SESSION['user_id']}";
$result = mysqli_query($con,$querry);

$result = $result->fetch_assoc();

if($result['balance'] >= $priceSum)
{
  $newBalance = $result['balance'] - $priceSum;
  $querry ="UPDATE users set balance = {$newBalance} where user_id = {$_SESSION['user_id']}";
  mysqli_query($con,$querry);
?>
<div class="logo">
  <img src="transactionimage.png">
</div>
<div class="bordermaking">
<?php
  echo "Your Total Bill is: ". $priceSum. "<br>";
  echo "Ticket Booked successfully". "<br>";
  echo "Your New Balance is: ". $newBalance;
  ?>
</div>
<?php
}
else {
  echo "You don't Have Enough Balance";
}

?>
