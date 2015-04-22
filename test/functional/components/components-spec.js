'use strict';
/**
 * OE Components Spec
 */

describe('OE Components', function() {

  beforeEach(function(){
    isAngularSite(false);
  });

  it('includes a Heading component', function(){
    browser.get(browser.params.url + '/admin/structure/paragraphs');
    //expect(element(by.xpath("//table/tbody/tr/td[contains(text(),'Heading')]")).isPresent()).toBe(true);
    expect(element(by.xpath("//table/tbody/tr[td='Heading (heading)']")).isPresent()).toBe(true);
  });

  it('includes a Long text component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='Long text (long_text)']")).isPresent()).toBe(true);
  });

  it('includes a HTML component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='HTML (html)']")).isPresent()).toBe(true);
  });

  it('includes a Link component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='Link (link)']")).isPresent()).toBe(true);
  });

  it('includes an Image component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='Image (image)']")).isPresent()).toBe(true);
  });

  it('includes a Quote component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='Quote (quote)']")).isPresent()).toBe(true);
  });

  it('includes a Youtube embed component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='YouTube embed (youtube_embed)']")).isPresent()).toBe(true);
  });

  it('includes a Flickr embed component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='Flickr embed (flickr_embed)']")).isPresent()).toBe(true);
  });

  it('includes a SoundCloud embed component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='SoundCloud embed (soundcloud_embed)']")).isPresent()).toBe(true);
  });

  it('includes a Storify embed component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='Storify embed (storify_embed)']")).isPresent()).toBe(true);
  });

});
