<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 *
 * @ingroup views_templates
 */
?>
	<h3>
		<?php if (!empty($title) || !empty($caption)): ?>
			<?php print str_replace("Agency: ", "", $title); ?>
		<?php endif; ?>
	</h3>
	<div class="section">
		<table <?php if ($classes): ?> class="<?php print $classes; ?>"<?php endif ?><?php print $attributes; ?>>
		  <?php if (!empty($header)) : ?>
		  	<caption class="">Website-Specific Reports</caption>
			<thead>
			  <tr>
				<?php foreach ($header as $field => $label): ?>
				  <th <?php if ($header_classes[$field]): ?> class="<?php print $header_classes[$field]; ?>"<?php endif; ?> scope="col">
					<?php print $label; ?>
				  </th>
				<?php endforeach; ?>
			  </tr>
			</thead>
		  <?php endif; ?>
		  <tbody>
			<?php foreach ($rows as $row_count => $row): ?>
			  <tr <?php if ($row_classes[$row_count]): ?> class="<?php print implode(' ', $row_classes[$row_count]); ?>"<?php endif; ?>>
				<?php foreach ($row as $field => $content): ?>
				  <td <?php if ($field_classes[$field][$row_count]): ?> class="<?php print $field_classes[$field][$row_count]; ?>"<?php endif; ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
					<?php print $content; ?>
				  </td>
				<?php endforeach; ?>
			  </tr>
			<?php endforeach; ?>
		  </tbody>
		</table>
	</div>

