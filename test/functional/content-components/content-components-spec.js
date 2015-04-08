'use strict';
/**
 * OE Content Components Spec
 */

describe('OE Content Components', function() {

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

  it('includes a Pull quote component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='Pull quote (pull_quote)']")).isPresent()).toBe(true);
  });

  it('includes a Youtube component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='YouTube (youtube)']")).isPresent()).toBe(true);
  });

  it('includes a Flickr component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='Flickr (flickr)']")).isPresent()).toBe(true);
  });

  it('includes a SoundCloud component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='SoundCloud (soundcloud)']")).isPresent()).toBe(true);
  });

  it('includes a Storify component', function(){
    expect(element(by.xpath("//table/tbody/tr[td='Storify (storify)']")).isPresent()).toBe(true);
  });

});
