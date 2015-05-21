<?php

function ix_one_form($form, &$form_state) {

  $form['page_size'] = array(
    '#type' => 'textfield',
    '#title' => 'Number of results per page',
    '#default_value' => '500',
    '#description' => 'The number of results returned if the the total record set is larger than the page size.',
    );

  $form['api_call'] = array(
    '#type' => 'radios',
    '#options' => array(
      'formatted'   	=> t('Formatted'),
      'updated' 		=> t('Updated'),
      'subscribed'      => t('Subscribed'),
      'filtered'		=> t('Filtered'),
    ),
    '#title' => t('API Function Call'),
  );

  $form['api_call']['formatted'] = array(
    '#disabled' => TRUE,
  );

  $form['api_call']['subscribed'] = array(
    '#disabled' => TRUE,
  );

  $form['api_call']['filtered'] = array(
    '#disabled' => TRUE,
  );


  $form['ix_one_id'] = array(
  	'#type' => 'textfield',
  	'#title' => 'IX-One Product ID',
  	'#size' => 20,
  	'#maxlength' => 40,
    '#states' => array(
		'visible' => array(
        	':input[name="api_call"]' => array('value' => 'formatted'),
      		),
    	),
  	);

  $form['start_date'] = array(
  	'#type'	=> 'date',
  	'#title' => 'Start Date',
  	'#default_value' => array('year' => 2014, 'month' => 1, 'day' => 1),
  	'#description' => 'Products updated after this date will be displayed.',
  	'#required' => TRUE,
    '#states' => array(
		'visible' => array(
        	array(
        		array(':input[name="api_call"]' => array('value' => 'updated')),
        		'or',
        		array(':input[name="api_call"]' => array('value' => 'subscribed')),
      		),
      	  ),
    	),  	
  	);

  if (empty($form_state['num_filters'])) {
    $form_state['num_filters'] = 1;
  }

  for ($i = 1; $i <= $form_state['num_filters']; $i++) {
  	$form['filter_properties'][$i] = array(
  		'#type' => 'fieldset',
  		'#title' => 'Properties under which a call could consider itself to be filtered.',
  		);

  	$form['filter_properties'][$i]['property'] = array(
  		'#type' => 'select',
  		'#options' => drupal_map_assoc(array("CubicInches", "EntityName","BioBasedYN","CarbonFootprintYN","DiabeticFriendlyYN","FairTradeYN","GlutenFreeYN","GMPYN","GrassFedYN","HalalYN","KosherYN","LowGlycemicYN","NonGMOYN","NPAYN","OrganicYN","MadewithOrganicIngredients","PACAYN","PASAYN","RainForestAllianceYN","RealSealYN","SustainabilityYN","VeganYN","VegetarianYN","VeteransYN","WholeGrainYN","SustainedRelease","ReleaseNotation","IXOneId","VendorItemNumber","ManufacturerNameHeader","BrandName","ProductDescription","SecondaryProductDescription","TertiaryDescription","InProduction","PrimarySize","PrimarySizeUOM","SecondarySize","SecondarySizeUOM","TertiarySize","TertiarySizeUOM","DrainedWeight","DrainedWeightUOM","PrimarySizeText","DateAdded","DateCaptured","Status","IngredientsStatement","IngredientsChina","LabelsForEducation","QRCode","CaloriesPerGramListed","Biodegradable","BPAFreePackaging","BPAFreeLiner","Compostable","FoodserviceBulkPack","PrintOnPricing","RecycledMaterial","RecycledMaterialType","SoyInk","UPC12","EANNumber","GTIN","Height","Width","Depth","Cube","Weight","CatchWeightItem","GrossWeight","TareWeight","ProductIsAlsoCase","Recipe1","Recipe2","Recipe3","Recipe4","Recipe5","AlcoholContentPercent","AlcoholContentProof","CountryOfOriginName","JuicePercent","ContainerColor","RedemptionValues","ContainerMaterialAndSize","SulfitesPPM","MSDS","CodeDateType","CodeDateStamp","CodeDatePosition","CodeDateExample","CodeDateFormula","ShelfLifeDaysGuarantee","ShelfLifeDaysAtProduction","ManufacturerCodePosition","ManufacturerCodeExample","ManufacturerCodeFormula","ContainerType","PegHole","MerchandisedInTray","Perishable","ManufacturerNamePackaging","ManufacturerStreetPackaging","ManufacturerCityPackaging","ManufacturerStatePackaging","ManufacturerZipCodePackaging","ManufacturerCountryPackaging","ManufacturerPhoneNumberPackaging","ProductOf","Restriction","IsMasterProduct","RecycledMaterialStatement","ViticultureYN","BioDynamicYN","CradleToCradleYN","CrueltyFreeYN","EcoFisheryYN","ForLifeYN","HeartHealthyYN","PaleoYN","Allergens","FreeOf","ProcessedOnEquipment","AllergensAncillary","Contains","DoesNotContain","FatContent","SaltContent","SugarSweetener","MilkType","Process","AttributesAncillary","BioBasedCertifier","CarbonFootprintCertifier","DiabeticFriendlyCertifier","FairTradeCertifier","GlutenFreeCertifier","GMPCertifier","GrassFedCertifier","HalalCertifier","KosherCertification","KosherType","LowGlycemicCertifier","NonGMOCertifier","NPACertifier","OrganicCertifier","OrganicPercentage","PACACertifier","PASACertifier","RainForestAllianceCertifier","RealSealCertifier","SustainabilityCertifier","VeganCertifier","VegetarianCertifier","VeteransCertifier","WholeGrainCertifier","CertificationsAncillary","IngredientBreakout","IngredientsAncillary","ConsumerStorage","OpeningInstructions","UsageInstructions","CookingInstructions","InstructionsAncillary","QuestionorCommentsStatement","Slogan","Website","MarketingClaims","PackagingDescriptors","RecycleStatement","AncillaryPackagingInformation","AncillaryInformation","TransportationRestrictions","WarningLabels","RulesAndRegulationsAncillary","SupplementaryCodeDateInformation","ManufacturerCodeSupplementaryInformation","ManufacturerEmailAddressFromPackage","SupplyChainAncillary","SocialMedia","DietaryPreference","ViticultureCertifier","BioDynamicCertifier","CradleToCradleCertifier","CrueltyFreeCertifier","EcoFisheryCertification","ForLifeCertifier","HeartHealthyCertifier","PaleoCertifier","CalorieClaim","HighPotency","CopyrightTrademarkRegistered","CertifiedBCorporation","ShelfLifeAfterOpening","SocialMediaAddresses","SecondaryDrainedWeight","SecondaryDrainedWeightUOM","InnerPack","Nutrition","DateCreated","DateModified")        
  			),
		'#title' => 'Properties to filter on',
    '#default_value' => 'UPC12',
	);

  $form['filter_properties'][$i]['logic'] = array(
    '#type' => 'select',
    '#options' => drupal_map_assoc(array("=", "!=", ">", "<")),
    '#title' => 'Value',
    '#default_value' => '=',

  );


	$form['filter_properties'][$i]['value'] = array(
		'#type' => 'textfield',
	  	'#title' => 'Value',
	  	'#size' => 20,
	  	'#maxlength' => 40,
	);
  }

    $form['add_filter'] = array(
	    '#type' => 'submit',
	    '#value' => t('Add another filter'),
	    '#submit' => array('ix_one_add_filter'),
  	);
    $form['remove_filter'] = array(
	    '#type' => 'submit',
	    '#value' => t('Remove one filter'),
	    '#submit' => array('ix_one_remove_filter'),
  );




  	$form['display_properties'] = array(
  		'#type' => 'select',
  		'#multiple' => TRUE,
  		'#attributes' => array('size'=>8),
  		'#options' => drupal_map_assoc(array("CubicInches", "EntityName","BioBasedYN","CarbonFootprintYN","DiabeticFriendlyYN","FairTradeYN","GlutenFreeYN","GMPYN","GrassFedYN","HalalYN","KosherYN","LowGlycemicYN","NonGMOYN","NPAYN","OrganicYN","MadewithOrganicIngredients","PACAYN","PASAYN","RainForestAllianceYN","RealSealYN","SustainabilityYN","VeganYN","VegetarianYN","VeteransYN","WholeGrainYN","SustainedRelease","ReleaseNotation","IXOneId","VendorItemNumber","ManufacturerNameHeader","BrandName","ProductDescription","SecondaryProductDescription","TertiaryDescription","InProduction","PrimarySize","PrimarySizeUOM","SecondarySize","SecondarySizeUOM","TertiarySize","TertiarySizeUOM","DrainedWeight","DrainedWeightUOM","PrimarySizeText","DateAdded","DateCaptured","Status","IngredientsStatement","IngredientsChina","LabelsForEducation","QRCode","CaloriesPerGramListed","Biodegradable","BPAFreePackaging","BPAFreeLiner","Compostable","FoodserviceBulkPack","PrintOnPricing","RecycledMaterial","RecycledMaterialType","SoyInk","UPC12","EANNumber","GTIN","Height","Width","Depth","Cube","Weight","CatchWeightItem","GrossWeight","TareWeight","ProductIsAlsoCase","Recipe1","Recipe2","Recipe3","Recipe4","Recipe5","AlcoholContentPercent","AlcoholContentProof","CountryOfOriginName","JuicePercent","ContainerColor","RedemptionValues","ContainerMaterialAndSize","SulfitesPPM","MSDS","CodeDateType","CodeDateStamp","CodeDatePosition","CodeDateExample","CodeDateFormula","ShelfLifeDaysGuarantee","ShelfLifeDaysAtProduction","ManufacturerCodePosition","ManufacturerCodeExample","ManufacturerCodeFormula","ContainerType","PegHole","MerchandisedInTray","Perishable","ManufacturerNamePackaging","ManufacturerStreetPackaging","ManufacturerCityPackaging","ManufacturerStatePackaging","ManufacturerZipCodePackaging","ManufacturerCountryPackaging","ManufacturerPhoneNumberPackaging","ProductOf","Restriction","IsMasterProduct","RecycledMaterialStatement","ViticultureYN","BioDynamicYN","CradleToCradleYN","CrueltyFreeYN","EcoFisheryYN","ForLifeYN","HeartHealthyYN","PaleoYN","Allergens","FreeOf","ProcessedOnEquipment","AllergensAncillary","Contains","DoesNotContain","FatContent","SaltContent","SugarSweetener","MilkType","Process","AttributesAncillary","BioBasedCertifier","CarbonFootprintCertifier","DiabeticFriendlyCertifier","FairTradeCertifier","GlutenFreeCertifier","GMPCertifier","GrassFedCertifier","HalalCertifier","KosherCertification","KosherType","LowGlycemicCertifier","NonGMOCertifier","NPACertifier","OrganicCertifier","OrganicPercentage","PACACertifier","PASACertifier","RainForestAllianceCertifier","RealSealCertifier","SustainabilityCertifier","VeganCertifier","VegetarianCertifier","VeteransCertifier","WholeGrainCertifier","CertificationsAncillary","IngredientBreakout","IngredientsAncillary","ConsumerStorage","OpeningInstructions","UsageInstructions","CookingInstructions","InstructionsAncillary","QuestionorCommentsStatement","Slogan","Website","MarketingClaims","PackagingDescriptors","RecycleStatement","AncillaryPackagingInformation","AncillaryInformation","TransportationRestrictions","WarningLabels","RulesAndRegulationsAncillary","SupplementaryCodeDateInformation","ManufacturerCodeSupplementaryInformation","ManufacturerEmailAddressFromPackage","SupplyChainAncillary","SocialMedia","DietaryPreference","ViticultureCertifier","BioDynamicCertifier","CradleToCradleCertifier","CrueltyFreeCertifier","EcoFisheryCertification","ForLifeCertifier","HeartHealthyCertifier","PaleoCertifier","CalorieClaim","HighPotency","CopyrightTrademarkRegistered","CertifiedBCorporation","ShelfLifeAfterOpening","SocialMediaAddresses","SecondaryDrainedWeight","SecondaryDrainedWeightUOM","InnerPack","Nutrition","DateCreated","DateModified")
  		),
		'#title' => 'Properties to Display',
	);

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Click Here!'),
  );


  
  return $form;
}

/**
 * Submit handler for "Add another name" button on form_example_tutorial_9().
 *
 * $form_state['num_names'] tells the form builder function how many name
 * fieldsets to build, so here we increment it.
 *
 * All elements of $form_state are persisted, so there's no need to use a
 * particular key, like the old $form_state['storage']. We can just use
 * $form_state['num_names'].
 *
 * @ingroup form_example
 */
function ix_one_add_filter($form, &$form_state) {
  // Everything in $form_state is persistent, so we'll just use
  // $form_state['add_name']
  $form_state['num_filters']++;
  //var_dump($form_state);

  // Setting $form_state['rebuild'] = TRUE causes the form to be rebuilt again.
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for "Remove name" button on form_example_tutorial_9().
 *
 * @ingroup form_example
 */
function ix_one_remove_filter($form, &$form_state) {
  if ($form_state['num_filters'] > 1) {
    $form_state['num_filters']--;
  }

  // Setting $form_state['rebuild'] = TRUE causes the form to be rebuilt again.
  $form_state['rebuild'] = TRUE;
}

function ix_one_form_submit($form, &$form_state) {

  $filter[0]['value'] = $form_state['values']['value'];
  $filter[0]['property'] = $form_state['values']['property'];
  $filter[0]['logic'] = $form_state['values']['logic'];

  $display = array_values($form_state['values']['display_properties']);

  $page_size = $form_state['values']['page_size'];

  $start_date = implode("/", $form_state['values']['start_date']);

  $items = getItems($page_size, 'updated', $start_date, $filter, $display);
  //var_dump($items);
  foreach($items as $item)
  {
    echo("<pre>");
    var_dump($item);
    echo("</pre>");
  }
  die();
  //drupal_set_message($items);
}

/**
 * Callback for autotextfields.
 *
 * Selects the piece of the form we want to use as replacement text and returns
 * it as a form (renderable array).
 *
 * @return array
 *   Renderable array (the textfields element)
 */
function ix_one_autotextfields_callback($form, $form_state) {
  return $form['textfields'];
}