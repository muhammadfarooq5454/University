<?php
header('location:index.php');

$con = mysqli_connect('localhost','root');

if($con)
{
	echo "connection successfull";
}
else
{
	echo "Failed to connect";
}

mysqli_select_db($con,'frendb');

$name = $_POST['username'];
$pass = $_POST['password'];

$q = " select * from users where username='{$name}' && password='{$pass}' ";

$result = mysqli_query($con,$q);

$num = mysqli_num_rows($result);

if($num == 1)
{
	echo "Duplicate Data";
	header('location:index.php');
}
else
{
	$qy = " insert into users(username , password) values ('{$name}','{$pass}') ";
	mysqli_query($con,$qy);
}

?>
