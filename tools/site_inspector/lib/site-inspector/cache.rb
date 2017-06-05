class SiteInspector
  class Cache
    def memory
      @memory ||= {}
    end

    def get(request)
      memory[request]
    end

    def set(request, response)
      memory[request] = response
    end
  end
end
