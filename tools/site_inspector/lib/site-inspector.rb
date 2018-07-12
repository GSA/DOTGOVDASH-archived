require 'open-uri'
require 'addressable/uri'
require 'public_suffix'
require 'typhoeus'
require 'parallel'
require 'cliver'
require 'cgi'

require_relative 'site-inspector/cache'
require_relative 'site-inspector/disk_cache'
require_relative 'site-inspector/rails_cache'
require_relative 'site-inspector/domain'
require_relative 'site-inspector/checks/check'
require_relative 'site-inspector/checks/accessibility'
require_relative 'site-inspector/checks/content'
require_relative 'site-inspector/checks/dns'
require_relative 'site-inspector/checks/headers'
require_relative 'site-inspector/checks/hsts'
require_relative 'site-inspector/checks/https'
require_relative 'site-inspector/checks/sniffer'
require_relative 'site-inspector/checks/cookies'
require_relative 'site-inspector/endpoint'
require_relative 'site-inspector/version'
require_relative 'cliver/dependency_ext'

class SiteInspector
  class << self
    attr_writer :timeout, :cache, :typhoeus_options

    def cache
      @cache ||= if ENV['CACHE']
        SiteInspector::DiskCache.new
      elsif Object.const_defined?('Rails')
        SiteInspector::RailsCache.new
      else
        SiteInspector::Cache.new
      end
    end

    def timeout
      @timeout || 10
    end

    def inspect(domain)
      Domain.new(domain)
    end

    def typhoeus_defaults
      defaults = {
        followlocation:  false,
        timeout:         SiteInspector.timeout,
        accept_encoding: 'gzip',
        method:          :head,
        headers:         {
          'User-Agent' => "Mozilla/5.0 (compatible; SiteInspector/#{SiteInspector::VERSION}; +https://github.com/benbalter/site-inspector)"
        }
      }
      defaults.merge! @typhoeus_options if @typhoeus_options
      defaults
    end

    # Returns a thread-safe, memoized hydra instance
    def hydra
      Typhoeus::Hydra.hydra
    end
  end
end

if ENV['DEBUG']
  Ethon.logger = Logger.new(STDOUT)
  Ethon.logger.level = Logger::DEBUG
  Typhoeus::Config.verbose = true
end

Typhoeus::Config.memoize = true
Typhoeus::Config.cache = SiteInspector.cache
