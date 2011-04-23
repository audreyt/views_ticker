<?php
// $Id$

/**
 * @file
 * Displays a scrolling list.
 *
 * @ingroup views_templates
 */
?>
<!-- start scroll -->
<?php
print "<div class='view view-$viewname'><div class='view-content view-content-$viewname'>";
if ($scroller_type == 'vertical' || $scroller_type == 'horizontal') {
  print "<div id='views-ticker-$align-$viewname' class='views-$align-container'>";
  print "<div class='$direction $speed $jmouse $delay $bounce'>";
}
else {
  print "<div id='views-ticker-$align-$viewname'>";
  print "<ul id='views-ticker-fade-$viewname'>";
}
foreach ($rows as $row) {
  if ($scroller_type == 'vertical' || $scroller_type == 'horizontal') {
    print "<div class='views-$align-item views-$align-item-$viewname'>";
    print "<span class='views-$align-tick-field views-$align-tick-field-$field'>$row</span></div>";
  }
  else {
    print "<li class='views-fade-item views-fade-item-$viewname'>";
    print "<span class='views-fade-tick-field views-fade-tick-field-$field'>$row</span></li>";
  }
}
if ($scroller_type == 'vertical' || $scroller_type == 'horizontal') {
  print "</div>";
  // continuous scrolling
  print "<div class='" . $direction . "_endless'>";
  foreach ($rows as $row) {
    print "<div class='views-$align-item views-$align-item-$viewname'>";
    print "<span class='views-$align-tick-field views-$align-tick-field-$field'>$row</span></div>";
  }
  print "</div></div></div></div>";
}
else {
  print "</ul></div></div></div>";
}
?>
<!-- end scroll -->
