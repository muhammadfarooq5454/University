<!DOCTYPE html>
<html>
<head>
  <title></title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>
<body>
  <?php include 'header.php'; ?>
 <div class="row">
<?php
include 'config.php';
//if($con)
//{
//echo "Connection successful";
//}
//else
//{
 // echo "Connection failed";
//}

$querry ="SELECT * FROM product order by id ASC";
$querryfire=mysqli_query($con,$querry);
$num=mysqli_num_rows($querryfire);

session_start();

if($num>0)
{
  while($prdt=mysqli_fetch_array($querryfire))
  {
    ?>
      <div class="col-lg-3 col-med-3 col-sm-12">

        <form>
          <div class="card">
            <h6 class="card title bg-info text-white p-2 text-uppercase "><?php echo $prdt['name'];
            ?></h6>

            <div class="card body">
             <img src="<?php echo $prdt['image']; ?> " alt="grocery" class="img-fluid mb-2">

              <h6> &#8360; <?php echo $prdt['price']; ?><span>(<?php echo $prdt['discount'];  ?>)% off </span></h6>

              <h6 class="badge badge-success">4.4<i class="fa fa-star"></i></h6>

            </div>
           <div class="btn-group d-flex">
                        <a href="addtocart.php?id=<?php echo $prdt['id']; ?>" class="btn btn-success flex-fill">Add to Cart</a></div>
          </div>

          </div>
        </form>


      </div>

    <?php
  }
}


?>
</body>
</html>
