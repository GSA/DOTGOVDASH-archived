<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
$mobsnap = dotgov_common_getMobileSnapshot(arg(1));
$output = $mobsnap;
$file_size = filesize($output['uri']);
$output =  image_style_url("thumbnail", $output['uri'] );
$outputorig =  	file_create_url($mobsnap['uri']);

?>
<?php //print $output; ?>

<div class="col-xs-12  white-back">
<div class="col-xs-4 text-center">
<h3>Agency</h3>
<p><?php print($row->field_field_parent_agency_name[0]['rendered']['#markup']); ?></p>
</div>

<div class="col-xs-4 text-center">
        <?php
        if($file_size != 0){
        ?>
    <a href="<?=$outputorig?>">
        <img src="<?php echo $output?>" title="agency-logo" alt="agency-logo" /></a>
</a>
    <?php } ?>
</div>

<div class="col-xs-3 text-center"><h3>Website</h3>
<p><?php print($row->field_body[0]['rendered']['#markup']); ?></p>
</div>
</div>

