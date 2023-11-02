
<?php
include "config.php";
session_start();

$name = $_POST['username'];
$pass = $_POST['password'];

$q = " select * from users where username='{$name}' && password='{$pass}' ";

$result = mysqli_query($con,$q);
$result = $result->fetch_assoc();

if(isset($result))
{
	$_SESSION['user_id'] = $result['user_id'];
	$_SESSION['username'] = $name;
	header('location:Homepage.php');
}
else
{
	header('location:index.php');
}


?>
