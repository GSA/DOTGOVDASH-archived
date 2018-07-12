This module provides a plugin that renders a view as a table with both row and
column headings.

By default, Views only renders tables with column headings. However, to ensure
that websites are usable for users who rely on screen readers, such as users
with blindness, it is sometimes necessary to render long or complex tables with
row headings as well as column headings. For more information, see
http://www.w3.org/WAI/tutorials/tables/two-headers/.

To set the row headings, set the view format to "Table with row headers". In the
settings form, there is a select that lists all fields in the view. Select one
to be the row header, or select "None" to have a table with no row headers.

It is conventional, but not required, to make the left-most column the row
header. The selection of a row header should be made semantically, based on what
would be the best label for the row. The second column may be the row header
first column is the row number or a Views Bulk Operation checkbox, for example.

Some may want to avoid having row headers because they may not want the visual
style for teach data cell to be the same throughout the row. However, it is
important for accessibility that semantic markup be used, especially for tables.
Use CSS to style row headers similarly to other cells.
