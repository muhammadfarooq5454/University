<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link href="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
	<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.0.8/css/all.css">
	<link rel="stylesheet" type="text/css" href="Login.css">
</head>
<body>
	<img src="Fren.png" class="image">
	<div class="center">		
<aside class="col-sm-4">
<div class="card">
<article class="card-body">
	<h4 class="card-title text-center mb-4 mt-1">Sign in</h4>
	<hr>
	<form action="registration.php" method="post">
	<div class="form-group">
		<div class="input-group">
			<div class="input-group-prepend">
		 	   <span class="input-group-text"> <i class="fa fa-user"></i> </span>
		 	</div>
			<input name="username" class="form-control" placeholder="username" type="text">
		</div> <!-- input-group.// -->
	</div> <!-- form-group// -->
	
	<div class="form-group">
		<div class="input-group">
			<div class="input-group-prepend">
		    	<span class="input-group-text"> <i class="fa fa-lock"></i> </span>
		</div>
	    <input name="password" class="form-control" placeholder="******" type="password">
		</div> <!-- input-group.// -->
	</div> <!-- form-group// -->
	
	<div class="form-group">
		<button type="submit" class="btn btn-primary"> 
			Signin 
		</button>
	</div> <!-- form-group// -->
	</form>
</article>
</div> <!-- card.// -->
	</aside> <!-- col.// -->

<aside class="col-sm-4">
<div class="card">
<article class="card-body">
	<h4 class="card-title text-center mb-4 mt-1">Login</h4>
	<hr>
	<form action="validation.php" method="post">
	<div class="form-group">
	<div class="input-group">
		<div class="input-group-prepend">
		    <span class="input-group-text"> <i class="fa fa-user"></i> </span>
		 </div>
		<input name="username" class="form-control" placeholder="username" type="text">
	</div> <!-- input-group.// -->
	</div> <!-- form-group// -->
	<div class="form-group">
	<div class="input-group">
		<div class="input-group-prepend">
		    <span class="input-group-text"> <i class="fa fa-lock"></i> </span>
		 </div>
	    <input name="password" class="form-control" placeholder="******" type="password">
	</div> <!-- input-group.// -->
	</div> <!-- form-group// -->
	<div class="form-group">
	<button type="submit" class="btn btn-primary"> 
		 Login 
	</button>
	</div> <!-- form-group// -->
	</form>
</article>
</div> <!-- card.// -->
	</aside> <!-- col.// -->
	</div>
</body>
</html>
