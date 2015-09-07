<?php
/**
 * @file
 * oe_person.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function oe_person_taxonomy_default_vocabularies() {
  return array(
    'person_title' => array(
      'name' => 'Person title',
      'machine_name' => 'person_title',
      'description' => 'A title is a prefix or suffix added to someone\'s name in certain contexts.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}

/**
 * Create person title taxonomy.
 */
function oe_person_taxonomy_title() {
  // Vocabulary details.
  $vocab = new stdClass();
  $vocab->name = 'Person title';
  $vocab->description = 'A title is a prefix or suffix added to someone\'s name in certain contexts.';
  $vocab->machine_name = 'person_title';

  // Default terms list.
  $terms = array(
    'Dame' => "Used by dames and baronetesses. <em>Sir</em> and <em>Dame</em> differ from titles such as <em>Mr</em> and <em>Mrs</em> in that they can only be used before a person's first name, and not immediately before their surname.",
    'Dr' => "Short for doctor, a title used by those with doctoral degrees, such as MD (Doctor of Medicine), PhD/DPhil (Doctor of Philosophy), EdD (Doctor of Education), PharmD (Doctor of Pharmacy) and LLD (Legum Doctor). Those with JD (Juris Doctor) degrees do not use this as a title.",
    'Hon' => "",
    'Miss' => "Formal title for unmarried females and for female children.",
    'MP' => "Member of the Parliament.",
    'Mr' => "Adult male.",
    'Mrs' => "Adult females (usually just for married females, widows, and divorcées).",
    'Ms' => "Adult females (used by those who are not strongly identified with their marital status or don't wish their marital status to be known; the female equivalent of Mr).",
    'Mx' => "Gender-neutral title (used by non-binary people as well as those who do not wish to reveal their gender).",
    'Prof' => "A professor is a scholarly teacher; the precise meaning of the term varies by country. Literally, professor derives from Latin as a 'person who professes' being usually an expert in arts or sciences, a teacher of the highest rank.",
    'Rev' => "The Reverend is a style most often used as a prefix to the names of Christian clergy and ministers. There are sometimes differences in the way the style is used in different countries and church traditions. The Reverend is correctly called a style but is often and in some dictionaries called a title, form of address or title of respect.",
    'Sir' => "Used by knights and baronets. <em>Sir</em> and <em>Dame</em> differ from titles such as <em>Mr</em> and <em>Mrs</em> in that they can only be used before a person's first name, and not immediately before their surname.",
  );

  // Vocabulary creation, if necessary.
  if (!taxonomy_vocabulary_machine_name_load($vocab->machine_name)) {
    taxonomy_vocabulary_save($vocab);
    drupal_set_message(st('New vocabulary %vocab created.', array('%vocab' => $vocab->name)));
  }

  // Terms creation or addition.
  $parent_title = taxonomy_vocabulary_machine_name_load($vocab->machine_name);
  // Iterate through the terms and add non existent ones.
  foreach ($terms as $name => $description) {
    $match = taxonomy_get_term_by_name($name, $parent_title->machine_name);
    if (empty($match)) {
      $term = new stdClass();
      $term->vid = $parent_title->vid;
      $term->name = $name;
      $term->description = $description;
      taxonomy_term_save($term);
      drupal_set_message(st('New term %term added to vocabulary %vocab.', array(
        '%term' => $name,
        '%vocab' => $parent_title->name,
      )));
    }
  }

}
