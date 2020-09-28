
$cas = 1
while($TRUE) {
	gen
	$ts = Measure-Command{Get-Content in | A > a.out}
	Write-Host time = $ts.TotalMilliseconds ms
	Get-Content in | bf > bf.out
	$a = Get-Content bf.out
	$b = Get-Content a.out
	# $res is Object[]
	$res = Compare-Object $a $b

	if($res.Count -eq 0) {
		Write-Host "#$cas ok`n" -ForegroundColor Green
	}
	else {
		Write-Host "#$cas wa`n"-ForegroundColor Red
		break;
	}
	$cas += 1
}

