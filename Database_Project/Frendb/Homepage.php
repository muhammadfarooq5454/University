<?php

session_start();
if(!isset($_SESSION['username']))
{
	header('location:Login.php');
}


?>

<!DOCTYPE html>
<html>
<head>
	<title>HomePage</title>
	<link href="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
	<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.0.8/css/all.css">
	<link rel="stylesheet" type="text/css" href="Homepage.css">
</head>
<body>
		<?php require 'header.php'; ?>
	<div class="container">
	<div class="heading">
		<h1>Welcome to Fren!</h1>
	</div>
	<div>
	</div>
	</div>
</body>
	</script>
</html>
