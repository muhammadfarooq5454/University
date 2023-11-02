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

$querry ="SELECT * FROM users u inner join kebills k on u.user_id = k.userid where u.user_id = {$_SESSION['user_id']} order by k.userid ASC";

$result = mysqli_query($con,$querry);

$num=mysqli_num_rows($result);

$result=$result->fetch_assoc();
//no need of fetching array in while loop as there is no array of items in this ke bills.php file//

if($result['balance'] >= $result['billamount'])
{
  $result['balance'] = $result['balance'] - $result['billamount'];

  $querry ="UPDATE users set balance = {$result['balance']} where user_id = {$_SESSION['user_id']}";
  mysqli_query($con,$querry);

  ?>
<div class="logo">
  <img src="transactionimage.png">
</div>
<div class="bordermaking">
<?php
  echo "Your Total Bill is: ". $result['billamount']. "<br>";
  echo "Transaction Successfull". "<br>";
  echo "Your New Balance is: ". $result['balance'];
  ?>
</div>
<?php
}
else {
  echo "You don't Have Enough Balance";
}

?>
