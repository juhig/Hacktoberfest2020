
<?php
	$height = $_POST["height"];
	$weight = $_POST["weight"];

	$bmi = ($weight / ($height ** 2))*10000;
	$bmi = round($bmi, 1);

	if ($bmi <= 18.5) {
		echo "Underweight";
	}
	elseif ($bmi <= 25) {
		echo "Normal weight";
	}
	elseif ($bmi < 30) {
		echo "Overweight";
	}
	else {
		echo "Obese";
	}
?>
