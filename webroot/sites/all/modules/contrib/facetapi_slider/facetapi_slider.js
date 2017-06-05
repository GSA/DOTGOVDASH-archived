(function ($) {

Drupal.behaviors.facetapi_slider = {
  attach: function(context, settings) {

    // Iterates over facets, applies slider widgets for block realm facets.
    for (var index in settings.facetapi.facets) {
      if (settings.facetapi.facets[index].makeSlider != null) {
        // Find the slider form with the matching Id.
        var $form = $('#' + settings.facetapi.facets[index].id, context);
        // Hide the form itself and create a slider.
        Drupal.facetapi_slider.makeSlider($form, settings.facetapi.facets[index]);
      }
    }
  }
}

/**
 * Class containing functionality for Facet API.
 */
Drupal.facetapi_slider = {};

/**
 * Applies the slider to a form.
 */
Drupal.facetapi_slider.makeSlider = function($form, settings) {
  var $wrapper = $( '<div id="slider-' + settings.id + '">\n\
    <span class="facetapi-slider-min"></span>\n\
    <div class="facetapi-slider"></div>\n\
    <span class="facetapi-slider-max" style="float:right"></span></div>').insertAfter($form);

  function set_slider_handle_labels(minval, maxval) {
    minval = parseFloat(minval);
    maxval = parseFloat(maxval);
    $form.find('input.facetapi-slider-min').val(minval.toFixed(settings.precision));
    $form.find('input.facetapi-slider-max').val(maxval.toFixed(settings.precision));
    // Calculate the position of the slider handles
    var $real_width = $wrapper.children('.facetapi-slider').width();
    var $range = settings.sliderMaxGlobal - settings.sliderMinGlobal;
    var $real_left = minval.toFixed(settings.precision) - settings.sliderMinGlobal;
    var $real_right = settings.sliderMaxGlobal - maxval.toFixed(settings.precision);;
    var $real_left_position = ($real_width/$range) * $real_left - 3;
    var $real_right_position = ($real_width/$range) * $real_right - 3;
    // Set the handles with text and position
    $wrapper.children('.facetapi-slider-min').text(settings.prefix + minval.toFixed(settings.precision).replace(/(\d)(?=(\d\d\d)+(?!\d))/g, "$1,") + settings.suffix);
    $wrapper.children('.facetapi-slider-max').text(settings.prefix + maxval.toFixed(settings.precision).replace(/(\d)(?=(\d\d\d)+(?!\d))/g, "$1,") + settings.suffix);

    $wrapper.children('.facetapi-slider-min').css("margin-left", $real_left_position + "px");
    $wrapper.children('.facetapi-slider-max').css("margin-right", $real_right_position + "px");
  }

  $wrapper.children('.facetapi-slider').slider({
    range: true,
    min: parseFloat(settings.sliderMinGlobal),
    max: parseFloat(settings.sliderMaxGlobal),
    step: settings.sliderStep,
    values: [settings.sliderMin, settings.sliderMax],
    slide: function (event, ui) {
      set_slider_handle_labels(ui.values[0], ui.values[1]);
    },
    stop: function(event, ui) {
      $form.submit();
    },
    create: function() {
      // add classes to slider handles, handy for styling
      $('.facetapi-slider > a:eq(0)').addClass('handle-min');
      $('.facetapi-slider > a:eq(1)').addClass('handle-max');
    }
  });

  set_slider_handle_labels(settings.sliderMin, settings.sliderMax);

  $form.hide();
}


})(jQuery);
