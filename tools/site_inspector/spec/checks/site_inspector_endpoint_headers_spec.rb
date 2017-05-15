require 'spec_helper'

describe SiteInspector::Endpoint::Headers do
  subject do
    stub_request(:head, 'http://example.com/')
      .to_return(status: 200, headers: { foo: 'bar' })
    endpoint = SiteInspector::Endpoint.new('http://example.com')
    SiteInspector::Endpoint::Headers.new(endpoint)
  end

  def stub_header(header, value)
    allow(subject).to receive(:headers) { { header => value } }
  end

  it 'parses the headers' do
    expect(subject.headers.count).to eql(1)
    expect(subject.headers.keys).to include('foo')
  end

  it 'returns a header' do
    expect(subject['foo']).to eql('bar')
    expect(subject.headers['foo']).to eql('bar')
  end

  it 'knows the server' do
    stub_header 'server', 'foo'
    expect(subject.server).to eql('foo')
  end

  it 'knows if a server has an xss protection header' do
    stub_header 'x-xss-protection', 'foo'
    expect(subject.xss_protection).to eql('foo')
  end

  it 'validates xss-protection' do
    stub_header 'x-xss-protection', 'foo'
    expect(subject.xss_protection?).to eql(false)

    stub_header 'x-xss-protection', '1; mode=block'
    expect(subject.xss_protection?).to eql(true)
  end

  it 'checks for clickjack proetection' do
    expect(subject.click_jacking_protection?).to eql(false)
    stub_header 'x-frame-options', 'foo'
    expect(subject.click_jacking_protection).to eql('foo')
    expect(subject.click_jacking_protection?).to eql(true)
  end

  it 'checks for CSP' do
    expect(subject.content_security_policy?).to eql(false)
    stub_header 'content-security-policy', 'foo'
    expect(subject.content_security_policy).to eql('foo')
    expect(subject.content_security_policy?).to eql(true)
  end

  it 'checks for strict-transport-security' do
    expect(subject.strict_transport_security?).to eql(false)
    stub_header 'strict-transport-security', 'foo'
    expect(subject.strict_transport_security).to eql('foo')
    expect(subject.strict_transport_security?).to eql(true)
  end
end
